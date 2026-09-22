# Requirements Traceability Matrix — RTM

| Business | Stakeholder | System | Architecture | Verification |
|---|---|---|---|---|
| BR-001 Gestão de usuários | ST-001 | FR-USER-001..007 | user/user_service/user_store | TC-USER-* |
| BR-002 Gestão de itens | ST-001 | FR-ITEM-001..003 | product/service | TC-ITEM-* |
| BR-003 Preservação | ST-005 | FR-PER-001 | persistence | TC-PER-* |
| BR-004 Modularidade | ST-003 | NFR-003/007/009 | architecture | AT-ARCH-* |
| BR-005 Segurança futura | ST-006 | FR-AUTH + NFR-005 | Account boundary | TC-AUTH-* |

## Estados de rastreabilidade

Specified → Designed → Implemented → Verified → Accepted.

Especificação não significa implementação concluída. Cada requisito deverá possuir evidência de verificação antes de ser considerado concluído.
