# Functional Requirements — Baseline 0.1

| ID | Requisito | Status |
|---|---|---|
| FR-USER-001 | Cadastrar usuário | Specified |
| FR-USER-002 | Gerar ID automaticamente | Specified |
| FR-USER-003 | Listar usuários ativos | Specified |
| FR-USER-004 | Buscar usuário por ID | Specified |
| FR-USER-005 | Atualizar cadastro | Specified |
| FR-USER-006 | Desativar usuário | Specified |
| FR-USER-007 | Reativar usuário | Specified |
| FR-ITEM-001 | Associar produto/ativo/serviço | Specified |
| FR-ITEM-002 | Listar itens associados | Specified |
| FR-ITEM-003 | Desativar item | Specified |
| FR-USER-008 | Pesquisa por nome/username/telefone | Future |
| FR-PER-001 | Persistência local | Planned |
| FR-AUTH-001 | Autenticação | Future |
| FR-AUTH-002 | Autorização | Future |

## Critérios principais

FR-USER-001: dados válidos devem criar usuário ativo e retornar seu ID.

FR-USER-002: IDs são positivos, únicos e não reutilizáveis.

FR-USER-003: somente usuários ativos são listados.

FR-USER-004: a busca por ID retorna cadastro e itens associados.

FR-USER-005: atualização preserva o ID.

FR-USER-006/007: desativação e reativação alteram estado, sem exclusão física.

FR-ITEM-001/002/003: itens podem ser associados, consultados e desativados.

FR-PER-001: estado confirmado deve sobreviver ao encerramento do processo.
