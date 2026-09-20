# login_term

Sistema de gerenciamento de usuários em terminal, desenvolvido em C.

O projeto tem como objetivo fornecer uma interface simples, rápida e orientada por menu para pesquisar, cadastrar e administrar usuários, além de controlar os produtos, ativos e serviços associados a cada cadastro.

## Objetivo

Construir uma ferramenta de gerenciamento cadastral executada diretamente no terminal, com arquitetura modular e preparada para evolução.

O sistema deve permitir:

- cadastrar novos usuários;
- gerar automaticamente um ID único para cada cadastro;
- listar usuários ativos;
- buscar usuários por ID;
- atualizar dados cadastrais;
- desativar e reativar usuários;
- consultar os dados completos de um usuário;
- registrar produtos, ativos e serviços utilizados por cada usuário;
- visualizar os itens atualmente ativos de cada usuário.

## O que o projeto resolve

O `login_term` centraliza informações básicas de usuários em uma aplicação de terminal, reduzindo a necessidade de manipulação manual de registros.

Cada cadastro pode possuir:

- ID;
- nome;
- telefone;
- username utilizado no cadastro;
- status ativo/inativo;
- produtos, ativos ou serviços associados.

A desativação de um usuário não remove o registro. O histórico permanece disponível para consulta e futuras operações de auditoria ou reativação.

## Arquitetura

A aplicação será organizada por responsabilidade:

```text
Terminal
   |
   v
+-----------+
|    UI     |  menu / entrada / saída
+-----+-----+
      |
      v
+-----------+
| Service   |  casos de uso
+-----+-----+
      |
      v
+-----------+
|  Domain   |  regras de negócio
+-----+-----+
      |
      v
+-----------+
|   Store   |  usuários em memória
+-----+-----+
      |
      v
+-----------+
|Persistence|  armazenamento permanente
+-----------+
```

Estrutura prevista:

```text
login_term/
├── include/
├── src/
├── core/
├── doc/
├── build/
├── obj/
├── Makefile
└── README.md
```

A interface de terminal não deve conhecer detalhes da persistência, e as regras de domínio não devem depender de impressão ou entrada de dados.

## Stack utilizada

- C;
- GCC ou Clang;
- Make;
- ambiente Unix/Linux como alvo inicial.

A implementação deve priorizar C portátil e dependências externas mínimas.

## Como usar

O projeto ainda está em fase inicial de desenvolvimento.

Quando o primeiro executável estiver disponível, a utilização prevista será:

```bash
make
./build/login_term
```

O programa apresentará um menu interativo no terminal.

## Fluxo inicial

```text
========================================
             LOGIN_TERM
        Gestão de Usuários
========================================

1. Listar usuários ativos
2. Cadastrar novo usuário
3. Buscar usuário por ID
4. Atualizar cadastro
5. Desativar usuário
6. Reativar usuário
7. Produtos / Ativos / Serviços
8. Usuários inativos
0. Sair
```

## Modelo de usuário

Exemplo conceitual:

```text
ID:        1001
Nome:      João da Silva
Telefone:  +55 11 99999-9999
Username:  joao.silva
Status:    ATIVO
```

Produtos, ativos ou serviços associados:

```text
[1] Plano Pro       | serviço | PRO-2026 | ATIVO
[2] Licença Desktop | produto | LIC-8891 | ATIVO
[3] API Premium     | serviço | API-1001 | ATIVO
```

## Regras importantes

O ID do usuário é gerado pelo sistema e não pode ser alterado pelo operador.

Desativar um usuário significa alterar seu estado para inativo. O registro não deve ser apagado fisicamente durante as operações normais.

Produtos e serviços também devem possuir estado próprio, permitindo manter histórico sem perda de dados.

A autenticação de credenciais será tratada separadamente do cadastro de usuário. Senhas não deverão ser armazenadas em texto puro.

## Documentação

A documentação técnica ficará em `doc/`, incluindo:

- requisitos;
- arquitetura;
- modelo de dados;
- fluxo do menu;
- roadmap.

## Roadmap

### Fase 1
Arquitetura, documentação e definição do modelo de dados.

### Fase 2
Implementação do núcleo em C:

- usuários;
- produtos/serviços;
- IDs;
- busca;
- atualização;
- ativação/desativação.

### Fase 3
Implementação do menu interativo.

### Fase 4
Persistência local.

### Fase 5
Autenticação e autorização.

### Fase 6
Evolução para SQLite, auditoria e pesquisas avançadas.

## Contribuição

Contribuições devem preservar a separação entre interface, aplicação, domínio e persistência.

Novas funcionalidades devem ser acompanhadas, quando necessário, de atualização da documentação correspondente.

## Status

Projeto em desenvolvimento inicial.
