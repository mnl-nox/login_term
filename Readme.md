# login_term

Sistema de gerenciamento de usuários em terminal, desenvolvido em C.

[![C](https://img.shields.io/badge/C-C17-A8B9CC?logo=c&logoColor=white)](https://en.cppreference.com/w/c/17)
[![GCC](https://img.shields.io/badge/GCC-Compiler-A42E2B?logo=gnu&logoColor=white)](https://gcc.gnu.org/)
[![Clang](https://img.shields.io/badge/Clang-Compiler-262D3A?logo=llvm&logoColor=white)](https://clang.llvm.org/)
[![Make](https://img.shields.io/badge/GNU%20Make-Build-204866?logo=gnu&logoColor=white)](https://www.gnu.org/software/make/)
[![Linux](https://img.shields.io/badge/Linux-Development-FCC624?logo=linux&logoColor=black)](https://www.linux.org/)
[![SQLite](https://img.shields.io/badge/SQLite-Planned-003B57?logo=sqlite&logoColor=white)](https://sqlite.org/)

## Visão geral

O `login_term` centraliza o cadastro e gerenciamento de usuários por meio de uma interface de terminal.

O sistema foi projetado para controlar dados cadastrais, status dos usuários e os produtos, ativos ou serviços associados a cada cadastro.

## O que o produto resolve

- Identificação única por usuário.
- Consulta rápida por ID.
- Cadastro e atualização de informações.
- Ativação e desativação sem apagar o histórico.
- Associação de produtos, ativos e serviços aos usuários.
- Base modular para futura persistência e autenticação.

## Funcionalidades

- [ ] Cadastrar usuário
- [ ] Gerar ID automaticamente
- [ ] Listar usuários ativos
- [ ] Buscar usuário por ID
- [ ] Atualizar cadastro
- [ ] Desativar / reativar usuário
- [ ] Gerenciar produtos, ativos e serviços
- [ ] Persistir dados localmente
- [ ] Autenticação e permissões

## Arquitetura

A aplicação segue separação de responsabilidades:

```text
Terminal UI
    ↓
Application / Services
    ↓
Domain
    ↓
Store / Repository
    ↓
Persistence
```

Estrutura:

```text
login_term/
├── include/    # Interfaces públicas
├── src/        # Implementação em C
├── core/       # Componentes centrais
├── doc/        # Documentação
├── build/      # Binários
└── obj/        # Objetos
```

## Padrões e princípios

- **C17** como padrão da linguagem.
- **Separação de responsabilidades** entre UI, aplicação, domínio e persistência.
- **Modularidade** com interfaces públicas em `include/`.
- **Soft delete** para desativação de usuários e itens.
- **ID gerado pelo sistema**, único e não reutilizado.
- **Conventional Commits** para mensagens de commit.
- Credenciais de autenticação separadas dos dados cadastrais e sem armazenamento de senha em texto puro.

## Documentação

- [Objetivos](doc/objective.md)
- [Requisitos](doc/requirements.md)
- [Arquitetura](doc/architecture.md)
- [Modelo de dados](doc/data-model.md)
- [Fluxo do menu](doc/menu-flow.md)
- [Roadmap](doc/roadmap.md)

## Compilação

A compilação será centralizada pelo `Makefile`.

```bash
make
make run
make clean
```

## Status

**Em desenvolvimento inicial.**

A prioridade atual é implementar o núcleo de gerenciamento de usuários e, em seguida, a interface de terminal e a persistência.

## Licença

A licença do projeto ainda não foi definida.
