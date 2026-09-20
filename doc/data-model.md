# Modelo de dados

## Entidade User

| Campo | Tipo C | Regra |
|---|---|---|
| id | unsigned int | obrigatório, único, gerado pelo sistema |
| name | char[] | obrigatório |
| phone | char[] | obrigatório na primeira versão |
| username | char[] | obrigatório e candidato a unicidade |
| active | bool | true = ativo; false = inativo |
| created_at | futuro | data/hora de criação |
| updated_at | futuro | última alteração |

## Entidade UserProduct

Representa qualquer produto, ativo ou serviço atualmente utilizado ou anteriormente associado ao usuário.

| Campo | Tipo C | Regra |
|---|---|---|
| id | unsigned int | identificador do vínculo/item |
| user_id | unsigned int | referência ao usuário |
| name | char[] | nome do produto/serviço |
| type | char[] | produto, ativo ou serviço |
| reference | char[] | código externo ou referência |
| active | bool | estado atual do vínculo |
| started_at | futuro | início da utilização |
| ended_at | futuro | fim da utilização, quando houver |

## Relação

Um usuário possui zero ou muitos produtos/ativos/serviços.

`User 1 ---- N UserProduct`

O ID do usuário é a chave principal lógica do cadastro. Os itens vinculados devem carregar a referência ao usuário, em vez de duplicar os dados cadastrais.

## Regra de exclusão

Não utilizar exclusão física para as operações normais de negócio. O padrão será soft delete/desativação por estado.

Isso preserva histórico e permite auditoria e reativação.
