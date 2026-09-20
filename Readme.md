# login_term

Sistema de gerenciamento de usuários em terminal, desenvolvido em C.

O projeto tem como objetivo fornecer uma interface simples e controlada para cadastrar, consultar, atualizar e administrar usuários, mantendo também o relacionamento com produtos, ativos e serviços utilizados por cada cadastro.

## Stack

- C
- GCC ou Clang
- Make
- Linux/Unix como ambiente principal de desenvolvimento
- Persistência local prevista para as próximas etapas
- SQLite previsto como evolução da camada de persistência

## O que é este projeto

O `login_term` é uma aplicação de gerenciamento cadastral executada diretamente no terminal.

O sistema será organizado em módulos independentes para separar:

- interface do terminal;
- regras de negócio;
- entidades e validações;
- gerenciamento dos usuários;
- persistência dos dados.

A arquitetura foi pensada para permitir que o armazenamento inicial seja simples e posteriormente evolua para SQLite sem exigir alterações significativas na interface do sistema.

## Funcionalidades

A primeira versão do sistema deverá permitir:

- cadastrar novos usuários;
- gerar automaticamente um ID único para cada usuário;
- listar usuários ativos;
- buscar usuários por ID;
- visualizar os dados cadastrais;
- atualizar informações cadastrais;
- desativar usuários sem apagar seus registros;
- reativar usuários;
- cadastrar produtos, ativos ou serviços vinculados ao usuário;
- listar os produtos, ativos e serviços associados;
- desativar itens vinculados mantendo seu histórico.

### Dados básicos do usuário

Cada cadastro deverá possuir inicialmente:

- ID;
- nome;
- telefone;
- username utilizado no cadastro;
- status ativo/inativo.

### Produtos, ativos e serviços

Cada item associado ao usuário deverá possuir:

- ID;
- ID do usuário;
- nome;
- tipo;
- referência/código;
- status ativo/inativo.

## Objetivo

Construir uma base de gerenciamento cadastral modular, previsível e extensível em C.

O projeto deve permitir adicionar novos campos ao cadastro e novas funcionalidades sem transformar a interface do terminal em uma camada responsável pelas regras internas do sistema.

## O que ele resolve

O sistema centraliza operações básicas de cadastro e gerenciamento de usuários em uma interface de terminal.

Entre os principais problemas tratados estão:

- identificação única dos usuários;
- consulta rápida por ID;
- manutenção dos dados cadastrais;
- controle do status dos usuários;
- relacionamento entre usuários e produtos/serviços;
- preservação do histórico após desativação.

## Arquitetura

A aplicação segue uma separação por responsabilidades:

```text
Terminal
   |
   v
+----------------+
|      UI        |
| menu / input   |
+-------+--------+
        |
        v
+----------------+
|  Application   |
| user_service   |
+-------+--------+
        |
        v
+----------------+
|    Domain      |
| user / product |
+-------+--------+
        |
        v
+----------------+
|     Store      |
|   user_store   |
+-------+--------+
        |
        v
+----------------+
|  Persistence   |
| file / SQLite  |
+----------------+
```

### Diretórios

```text
login_term/
├── include/    # Interfaces públicas dos módulos
├── src/        # Implementação em C
├── core/       # Componentes centrais
├── doc/        # Documentação técnica
├── build/      # Binários gerados
├── obj/        # Arquivos objeto
├── Makefile
└── Readme.md
```

## Regras importantes

### ID

O ID do usuário é gerado pelo sistema.

O operador não informa o ID durante o cadastro.

O ID deve:

- ser único;
- ser positivo;
- permanecer associado ao usuário;
- não ser reutilizado após uma atribuição.

### Desativação

A remoção normal de usuários será lógica, não física.

Em vez de apagar o registro:

```text
active = false
```

Isso preserva o histórico e permite futuras operações de auditoria e reativação.

### Cadastro x autenticação

Apesar do nome `login_term`, o cadastro de usuários não deve ser confundido com autenticação.

Em uma etapa posterior, as credenciais poderão ser representadas separadamente:

```text
Account
   |
   v
User
```

Senhas não deverão ser armazenadas em texto puro. A autenticação deverá utilizar mecanismos apropriados de hash e controle de sessão.

## Como compilar

A compilação será centralizada pelo `Makefile).

A interface planejada será:

```bash
make
make clean
make run
```

Os comandos disponíveis poderão evoluir conforme o sistema de build for implementado.

## Como executar

Após a compilação:

```bash
./build/login_term
```

A aplicação deverá apresentar o menu principal:

```text
========================================
             LOGIN_TERM
        Gestão de Usuários
========================================

1. Listar usuários ativos
2. Novo usuário
3. Buscar usuário por ID
4. Atualizar cadastro
5. Desativar usuário
6. Reativar usuário
7. Produtos / Ativos / Serviços
8. Usuários inativos
0. Sair
```

## Documentação

A documentação técnica está organizada em `doc/`:

- `objective.md` — objetivos do projeto;
- `requirements.md` — requisitos funcionais e não funcionais;
- `architecture.md` — arquitetura e responsabilidades dos módulos;
- `data-model.md` — modelo de dados;
- `menu-flow.md` — fluxos da interface;
- `roadmap.md` — etapas planejadas de desenvolvimento.

## Roadmap

### Fase 1 — Arquitetura
- [x] Estrutura inicial do projeto
- [x] Definição do modelo de usuário
- [x] Definição do relacionamento com produtos/serviços
- [x] Documentação arquitetural

### Fase 2 — Núcleo
- [ ] Implementação de `User`
- [ ] Implementação de produtos/serviços
- [ ] Store de usuários
- [ ] Geração de IDs
- [ ] Validações
- [ ] Operações de ativação/desativação

### Fase 3 — Terminal
- [ ] Menu principal
- [ ] Cadastro
- [ ] Listagem
- [ ] Busca por ID
- [ ] Atualização cadastral
- [ ] Desativação/reativação
- [ ] Gerenciamento de produtos/serviços

### Fase 4 — Persistência
- [ ] Salvamento local
- [ ] Carregamento automático
- [ ] Validação do arquivo de dados
- [ ] Backup
- [ ] Versionamento do formato

### Fase 5 — Autenticação
- [ ] Contas de acesso
- [ ] Hash de senha
- [ ] Sessões
- [ ] Permissões

### Fase 6 — Evolução
- [ ] SQLite
- [ ] Pesquisa por nome
- [ ] Pesquisa por username
- [ ] Pesquisa por telefone
- [ ] Auditoria
- [ ] Relatórios

## Contribuição

Contribuições devem preservar a separação entre interface, domínio, serviços e persistência.

Antes de adicionar uma funcionalidade, documente sua responsabilidade e, quando necessário, atualize os arquivos correspondentes em `doc/`.

Commits devem ser pequenos e descritivos, preferencialmente seguindo o padrão:

```text
feat: nova funcionalidade
fix: correção de comportamento
docs: atualização de documentação
refactor: reorganização interna
test: testes
build: alterações no sistema de compilação
```

## Status

Projeto em desenvolvimento inicial.

A prioridade atual é implementar o núcleo de gerenciamento de usuários antes de adicionar persistência complexa ou autenticação.
