# Non-Functional Requirements — Baseline 0.1

| ID | Categoria | Requisito | Verificação |
|---|---|---|---|
| NFR-001 | Linguagem | C23 | Build |
| NFR-002 | Portabilidade | Evitar dependência desnecessária de um SO | Build/teste |
| NFR-003 | Arquitetura | UI, aplicação, domínio e persistência separados | Inspeção |
| NFR-004 | Integridade | IDs gerados e não reutilizados | Teste |
| NFR-005 | Segurança | Credenciais futuras não em texto puro | Inspeção/teste |
| NFR-006 | Persistência | Estado sobrevive ao processo | Teste |
| NFR-007 | Manutenibilidade | Interfaces pequenas e responsabilidades claras | Revisão |
| NFR-008 | Testabilidade | Núcleo exercitável sem UI | Teste |
| NFR-009 | Evolutividade | Persistência substituível | Inspeção |
| NFR-010 | Usabilidade | Desativação exige confirmação | Aceitação |
| NFR-011 | Confiabilidade | Entrada inválida não corrompe estado | Teste |
| NFR-012 | Auditoria futura | Arquitetura permite eventos/auditoria | Inspeção |
