# login_term

Sistema de gerenciamento de usuários em terminal, desenvolvido em **C23**.

<p>
  <img src="assets/svg/c23.svg" alt="C23" height="40">
  <img src="assets/svg/gcc.svg" alt="GCC" height="40">
  <img src="assets/svg/clang.svg" alt="Clang" height="40">
  <img src="assets/svg/make.svg" alt="GNU Make" height="40">
  <img src="assets/svg/linux.svg" alt="Linux" height="40">
  <img src="assets/svg/sqlite.svg" alt="SQLite" height="40">
</p>

[![C23](https://img.shields.io/badge/C-C23-A8B9CC?logo=c&logoColor=white)](https://en.cppreference.com/w/c/23)
[![GCC](https://img.shields.io/badge/GCC-Compiler-A42E2B?logo=gnu&logoColor=white)](https://gcc.gnu.org/)
[![Clang](https://img.shields.io/badge/Clang-Compiler-262D3A?logo=llvm&logoColor=white)](https://clang.llvm.org/)
[![GNU Make](https://img.shields.io/badge/GNU%20Make-Build-204866?logo=gnu&logoColor=white)](https://www.gnu.org/software/make/)
[![Linux](https://img.shields.io/badge/Linux-Development-FCC624?logo=linux&logoColor=black)](https://www.linux.org/)
[![SQLite](https://img.shields.io/badge/SQLite-Planned-003B57?logo=sqlite&logoColor=white)](https://sqlite.org/)

## Visão geral

O `login_term` centraliza o cadastro e gerenciamento de usuários em uma interface de terminal.

O produto controla dados cadastrais, status e os produtos, ativos ou serviços associados a cada usuário.

## O que o produto resolve

- Identificação única e consulta por ID.
- Cadastro e atualização de informações.
- Ativação e desativação sem exclusão física.
- Relacionamento entre usuários e produtos/serviços.
- Preservação do histórico cadastral.
- Base modular para futura persistência e autenticação.

## Funcionalidades

- [ ] Cadastro de usuários
- [ ] Geração automática de ID
- [ ] Listagem de usuários ativos
- [ ] Busca por ID
- [ ] Atualização cadastral
- [ ] Desativação e reativação
- [ ] Produtos, ativos e serviços
- [ ] Persistência local
- [ ] Autenticação e permissões


## Arquitetura

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

Diagramas UML:

- [Casos de uso](src/uml/use-cases.svg)
- [Modelo de classes](src/uml/class-model.svg)
- [Arquitetura de componentes](src/uml/component-architecture.svg)


## Padrões e princípios

- **C23** como padrão da linguagem.
- **Separação de responsabilidades**.
- **Modularidade** através de headers em `include/`.
- **Soft delete** para usuários e itens.
- **ID gerado pelo sistema**, único e não reutilizado.
- **Conventional Commits**.
- Credenciais de autenticação isoladas dos dados cadastrais.
- Persistência desacoplada da regra de negócio.

## Documentação

- [Objetivos](doc/objective.md)
- [Requisitos](doc/requirements.md)
- [Arquitetura](doc/architecture.md)
- [Modelo de dados](doc/data-model.md)
- [Fluxo do menu](doc/menu-flow.md)
- [Roadmap](doc/roadmap.md)

## Compilação

O projeto utiliza `Makefile` e deve compilar explicitamente em C23:

```bash
make
make run
make clean
```

Compiladores previstos:

- GCC
- Clang

## Status

**Em desenvolvimento inicial.**

Prioridade atual: implementar o núcleo de gerenciamento de usuários, seguido pela interface de terminal e persistência.

## Licença

A licença do projeto ainda não foi definida.
