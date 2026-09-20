# Fluxo do menu

## Menu principal

```
========================================
             LOGIN_TERM
        Gestão de Usuários
========================================

1. Listar usuários ativos
2. Novo usuário
3. Buscar usuário por ID
4. Atualizar cadastro
5. Desativar usuário
6. Reativar usuário
7. Produtos / Ativos / Serviços
8. Usuários inativos
0. Sair
```

## Novo usuário

```
Nome:
Telefone:
Username:

Confirmar cadastro? [S/N]

Usuário criado.
ID: 1001
Status: ATIVO
```

## Consulta

```
ID: 1001
Nome: ...
Telefone: ...
Username: ...
Status: ATIVO

Produtos / Serviços:
[1] ...
[2] ...
```

## Atualização

A atualização deve localizar o usuário primeiro pelo ID e então oferecer edição por campo.

O ID é imutável.

## Desativação

Antes de desativar, o sistema deve mostrar o usuário encontrado e exigir confirmação explícita.

A ação altera somente o estado do cadastro.

## Gerenciamento de produtos

O submenu deve operar sobre o usuário selecionado:

```
1. Listar itens
2. Adicionar item
3. Desativar item
4. Voltar
```
