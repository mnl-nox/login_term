# Requisitos do sistema

## Objetivo

O login_term será um sistema de gerenciamento de usuários executado no terminal, escrito em C, com foco em cadastro, consulta, manutenção cadastral e controle dos produtos, ativos e serviços utilizados por cada usuário.

## Requisitos funcionais

### RF01 — Cadastrar usuário
O operador deverá informar os dados cadastrais básicos:
- nome;
- telefone;
- nome de usuário (username).

O sistema deverá gerar automaticamente um ID numérico único.

### RF02 — Listar usuários ativos
Exibir somente usuários com status ativo, apresentando pelo menos:
- ID;
- nome;
- telefone;
- username.

### RF03 — Buscar usuário por ID
Permitir localizar um usuário pelo ID e exibir seu cadastro completo e seus produtos/ativos/serviços associados.

### RF04 — Atualizar cadastro
Permitir alterar campos existentes sem modificar o ID do usuário.

A arquitetura deve permitir a inclusão futura de novos campos cadastrais sem exigir alterações na camada de menu.

### RF05 — Desativar usuário
O usuário deverá ser marcado como inativo. O registro não deverá ser fisicamente removido.

### RF06 — Reativar usuário
Permitir reativar um usuário previamente desativado.

### RF07 — Gerenciar produtos/ativos/serviços
Permitir:
- vincular um item ao usuário;
- listar os itens vinculados;
- desativar um item;
- manter o histórico do item.

### RF08 — Pesquisar usuários
Além da busca por ID, a arquitetura deverá permitir posteriormente pesquisas por nome, username e telefone.

## Requisitos não funcionais

### RNF01 — Linguagem
C padrão compatível com compiladores modernos, evitando dependências específicas de um único sistema operacional sempre que possível.

### RNF02 — Separação de responsabilidades
Interface, regras de negócio e persistência devem ser módulos independentes.

### RNF03 — Integridade
IDs não devem ser definidos manualmente pelo operador e não devem ser reutilizados depois de atribuições anteriores.

### RNF04 — Segurança
Dados de autenticação, quando implementados, não deverão ser armazenados em texto puro. Senhas deverão ser tratadas como credenciais e separadas do cadastro operacional.

### RNF05 — Persistência
A aplicação deverá sobreviver ao encerramento do processo. A primeira implementação pode usar armazenamento local simples; a arquitetura deve permitir evolução para SQLite.

### RNF06 — Manutenibilidade
Cada módulo deve possuir uma interface pública pequena e uma responsabilidade clara.

## Fora do escopo da primeira versão

- autenticação distribuída;
- recuperação de senha;
- integração com serviços externos;
- faturamento;
- pagamentos;
- controle completo de estoque;
- multiusuário concorrente em rede.
