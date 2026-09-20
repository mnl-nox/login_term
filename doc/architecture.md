# Arquitetura do login_term

## Visão

O projeto será organizado em camadas para evitar que a interface de terminal conheça detalhes de armazenamento ou das regras internas.

```
+---------------------------+
|        Terminal UI        |
|     menu.c / input.c      |
+-------------+-------------+
              |
              v
+---------------------------+
|       Application         |
|    user_service.c         |
+-------------+-------------+
              |
              v
+---------------------------+
|          Domain           |
| user.c / product.c        |
+-------------+-------------+
              |
              v
+---------------------------+
|       Repository          |
| user_store.c / ...        |
+-------------+-------------+
              |
              v
+---------------------------+
|       Persistence         |
| file.c -> SQLite futuro   |
+---------------------------+
```

## Componentes

### 1. main
Ponto de entrada. Inicializa dependências, carrega dados e inicia o menu.

### 2. menu
Responsável por:
- desenhar menus;
- receber entrada;
- validar o formato básico da entrada;
- chamar serviços;
- apresentar resultados.

O menu não deve manipular diretamente arrays internos de usuários.

### 3. application/service
Orquestra casos de uso como:
- cadastrar usuário;
- buscar usuário;
- atualizar cadastro;
- ativar/desativar;
- gerenciar itens vinculados.

Aqui ficam regras que envolvem mais de uma entidade ou uma sequência de operações.

### 4. domain
Contém estruturas e regras próprias de usuário e itens vinculados:
- validação;
- inicialização;
- mudança de estado;
- inclusão/remoção lógica de itens.

### 5. repository/store
Define operações sobre a coleção de usuários sem depender do terminal:
- inserir;
- buscar por ID;
- listar;
- atualizar;
- desativar;
- reativar.

Na primeira versão pode operar em memória.

### 6. persistence
Responsável por converter o estado da aplicação para um armazenamento permanente.

Primeiro alvo:
- arquivo local controlado pela aplicação.

Evolução:
- SQLite;
- migrações de esquema;
- transações.

## Estrutura de diretórios

```
login_term/
├── include/
│   ├── menu.h
│   ├── user.h
│   ├── product.h
│   ├── user_service.h
│   ├── user_store.h
│   └── persistence.h
├── src/
│   ├── main.c
│   ├── menu.c
│   ├── user.c
│   ├── product.c
│   ├── user_service.c
│   ├── user_store.c
│   └── persistence.c
├── core/
│   └── README.md
├── doc/
│   ├── architecture.md
│   ├── data-model.md
│   ├── menu-flow.md
│   ├── objective.md
│   ├── requirements.md
│   └── roadmap.md
├── build/
├── obj/
├── .gitignore
├── Makefile
└── Readme.md
```

## Limites de responsabilidade

O código deve seguir estas regras:

1. `menu.c` não acessa estruturas globais de persistência.
2. `user.c` não imprime mensagens no terminal.
3. `persistence.c` não conhece o menu.
4. `main.c` apenas inicializa e coordena o ciclo de execução.
5. Interfaces públicas ficam em `include/`.
6. Implementações ficam em `src/`.

## IDs

O ID de usuário será gerado por um componente central de armazenamento.

Regras:
- inicia em um valor positivo;
- nunca é solicitado ao operador;
- não é reutilizado;
- permanece associado ao usuário mesmo após desativação.

A persistência deverá salvar também o próximo ID disponível ou permitir derivá-lo com segurança a partir do armazenamento.

## Autenticação

Embora o nome do projeto seja login_term, autenticação não deve ser confundida com cadastro.

Em uma etapa futura, credenciais poderão ser modeladas separadamente:

`Account -> User`

O cadastro de cliente não deverá armazenar senha. A camada de autenticação será responsável por username, hash de senha, sessão e autorização.

## Extensibilidade

Novos campos cadastrais devem ser introduzidos no domínio e no modelo de persistência, enquanto o menu utiliza serviços para edição.

Isso permite adicionar no futuro, por exemplo:
- e-mail;
- documento;
- endereço;
- data de nascimento;
- observações;
- perfil/tipo de cliente;
- datas de criação e atualização.

