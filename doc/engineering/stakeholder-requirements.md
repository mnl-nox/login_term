# Stakeholder Requirements

| ID | Stakeholder | Necessidade |
|---|---|---|
| ST-001 | Operador | Cadastrar e consultar usuários |
| ST-002 | Administrador | Controlar ciclo de vida |
| ST-003 | Desenvolvedor | Manter módulos independentes e testáveis |
| ST-004 | Projeto | Controlar escopo, mudanças, riscos e entregas |
| ST-005 | Persistência | Manter estado consistente |
| ST-006 | Segurança futura | Separar conta/autenticação do cadastro |

## Requisitos derivados

- O operador deve informar os dados cadastrais obrigatórios.
- O sistema deve gerar ID único.
- Usuários devem ser localizáveis por ID.
- Atualizações não podem alterar o ID.
- Desativação não deve apagar fisicamente o registro.
- Itens devem permanecer relacionados ao usuário.
- A persistência deve ser substituível sem alterar o domínio.
- Autenticação futura deve ser modelada separadamente de User.
