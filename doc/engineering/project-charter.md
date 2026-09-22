# Project Charter — login_term

## Propósito
Estudo de caso de Projeto e Engenharia de Software aplicado a um sistema de gerenciamento de usuários em terminal, desenvolvido em C23.

## Objetivo do produto
Cadastrar, consultar e manter usuários e produtos/ativos/serviços associados, preservando histórico por desativação lógica.

## Escopo inicial
- cadastro de usuários;
- geração automática de ID;
- consulta por ID;
- listagem de ativos;
- atualização;
- desativação/reativação;
- itens associados;
- persistência local;
- arquitetura modular;
- testes e rastreabilidade.

## Fora do escopo inicial
Autenticação distribuída, recuperação de senha, integrações externas, faturamento, pagamentos, estoque completo e concorrência em rede.

## Restrições
C23; GCC/Clang; interface terminal; IDs gerados pelo sistema e não reutilizados; separação entre domínio, serviços, UI e persistência.

## Critérios de sucesso
Requisitos rastreáveis; arquitetura documentada; núcleo testável sem UI; mudanças controladas; critérios de aceitação definidos; releases relacionadas a requisitos e testes.

## Referenciais
PMBOK/PMI; ISO/IEC/IEEE 29148; ISO/IEC 25010; ISO/IEC/IEEE 12207; ISO 31000; ISO/IEC 27001/27002 quando aplicáveis.

> Estes referenciais são usados para estudo e estruturação. Não representam certificação ou conformidade formal.
