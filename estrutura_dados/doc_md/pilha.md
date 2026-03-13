# 📚 Guia Completo: Pilhas (Stacks) em C

## 🎯 O Que São Pilhas?

Uma **pilha** é uma estrutura de dados que segue o princípio **LIFO** (Last In, First Out):
- **Último a Entrar, Primeiro a Sair**
- Como uma pilha de pratos: você sempre pega o prato do topo
- Ou como o botão "voltar" do navegador: volta na ordem inversa que entrou

### **Operações Básicas:**
1. **PUSH** - Adicionar elemento no topo
2. **POP** - Remover elemento do topo
3. **TOP/PEEK** - Ver elemento do topo (sem remover)
4. **isEmpty** - Verificar se está vazia

---

## 🆚 Pilha Estática vs Pilha Dinâmica

### **Pilha Estática (Array)**
```
┌───────────────────────┐
│  Posição 0 │  Vazio  │
├────────────┼─────────┤
│  Posição 1 │  Vazio  │
├────────────┼─────────┤
│  Posição 2 │  Vazio  │  ← Tamanho FIXO (definido em #define TAM 5)
├────────────┼─────────┤
│  Posição 3 │  Vazio  │
├────────────┼─────────┤
│  Posição 4 │  Vazio  │
└────────────┴─────────┘
```
✅ Acesso rápido  
✅ Simples de implementar  
❌ Tamanho fixo (pode desperdiçar ou faltar memória)  
❌ Overflow se tentar adicionar além do limite  

### **Pilha Dinâmica (Lista Encadeada)**
```
┌────────┐    ┌────────┐    ┌────────┐
│ TOPO   │───→│ Meio   │───→│ Base   │
│ senha=3│    │ senha=2│    │ senha=1│
│  prox  │    │  prox  │    │  NULL  │
└────────┘    └────────┘    └────────┘
```
✅ Tamanho flexível (cresce sob demanda)  
✅ Não desperdiça memória  
❌ Usa mais memória por nó (precisa do ponteiro)  
❌ Acesso um pouco mais lento (ponteiros)  

---

## 📊 Analogias do Mundo Real

### **1. Pilha de Pratos**
```
    ┌─────────┐
    │ Prato 3 │ ← TOPO (último colocado, primeiro a sair)
    ├─────────┤
    │ Prato 2 │
    ├─────────┤
    │ Prato 1 │ ← BASE (primeiro colocado, último a sair)
    └─────────┘
```
- PUSH = Colocar prato em cima
- POP = Pegar prato do topo

### **2. Histórico do Navegador**
```
Página 1 (Google) → Página 2 (YouTube) → Página 3 (GitHub)
                                            ↑ Você está aqui
                                            
Clicar "Voltar":
Página 1 (Google) → Página 2 (YouTube)
                      ↑ Voltou (pop)
```

### **3. Função Undo (Ctrl+Z)**
```
Ação 1: Digitou "Hello"
Ação 2: Digitou "World"
Ação 3: Deletou "World"
         ↑ Última ação

Ctrl+Z → Desfaz Ação 3 (pop)
Ctrl+Z → Desfaz Ação 2 (pop)
```

---

## 🔧 PILHA ESTÁTICA: Análise Detalhada

### **Estrutura de Dados**
```c
#define TAM 5
int pilha[TAM];  // Array de tamanho fixo
int topo = -1;   // Índice do topo (-1 = vazia)
```

### **Representação na Memória**
```
topo = -1 (pilha vazia)

┌────────┬────────┬────────┬────────┬────────┐
│ [0]    │ [1]    │ [2]    │ [3]    │ [4]    │
│ lixo   │ lixo   │ lixo   │ lixo   │ lixo   │
└────────┴────────┴────────┴────────┴────────┘
                                ↑
                              TAM-1
```

---

## 🎬 ANIMAÇÃO: Push Estático (3 elementos)

### **Estado Inicial: Pilha Vazia**
```
topo = -1

┌────────┬────────┬────────┬────────┬────────┐
│ [0]    │ [1]    │ [2]    │ [3]    │ [4]    │
│        │        │        │        │        │
└────────┴────────┴────────┴────────┴────────┘
```

---

### **1º PUSH: push(1)**

#### **Passo 1: Verificar se está cheia**
```c
if(topo == TAM - 1){  // -1 == 4? NÃO
    printf("Pilha cheia!\n");
    return;
}
```

#### **Passo 2: Incrementar topo**
```c
topo++;  // topo = -1 + 1 = 0
```

#### **Passo 3: Inserir valor**
```c
pilha[topo] = senha;  // pilha[0] = 1
```

**Resultado:**
```
topo = 0
  ↓
┌────────┬────────┬────────┬────────┬────────┐
│ [0]    │ [1]    │ [2]    │ [3]    │ [4]    │
│   1    │        │        │        │        │
└────────┴────────┴────────┴────────┴────────┘
  BASE
```

---

### **2º PUSH: push(2)**

#### **Verificação + Incremento**
```c
if(topo == TAM - 1){  // 0 == 4? NÃO
    // Não entra
}

topo++;  // topo = 0 + 1 = 1
pilha[topo] = 2;  // pilha[1] = 2
```

**Resultado:**
```
        topo = 1
          ↓
┌────────┬────────┬────────┬────────┬────────┐
│ [0]    │ [1]    │ [2]    │ [3]    │ [4]    │
│   1    │   2    │        │        │        │
└────────┴────────┴────────┴────────┴────────┘
  BASE    TOPO
```

---

### **3º PUSH: push(3)**

```c
topo++;  // topo = 1 + 1 = 2
pilha[topo] = 3;
```

**Resultado:**
```
                topo = 2
                  ↓
┌────────┬────────┬────────┬────────┬────────┐
│ [0]    │ [1]    │ [2]    │ [3]    │ [4]    │
│   1    │   2    │   3    │        │        │
└────────┴────────┴────────┴────────┴────────┘
  BASE            TOPO
```

---

## 🎬 ANIMAÇÃO: Pop Estático

### **Estado Antes do POP**
```
                topo = 2
                  ↓
┌────────┬────────┬────────┬────────┬────────┐
│ [0]    │ [1]    │ [2]    │ [3]    │ [4]    │
│   1    │   2    │   3    │        │        │
└────────┴────────┴────────┴────────┴────────┘
```

### **Executando pop()**

#### **Passo 1: Verificar se está vazia**
```c
if(topo == -1){  // 2 == -1? NÃO
    printf("Pilha vazia!\n");
    return;
}
```

#### **Passo 2: Mostrar valor removido**
```c
printf("Senha %d foi retirada\n", pilha[topo]);
// Imprime: Senha 3 foi retirada
```

#### **Passo 3: Decrementar topo**
```c
topo--;  // topo = 2 - 1 = 1
```

**Resultado:**
```
        topo = 1
          ↓
┌────────┬────────┬────────┬────────┬────────┐
│ [0]    │ [1]    │ [2]    │ [3]    │ [4]    │
│   1    │   2    │   3    │        │        │
└────────┴────────┴────────┴────────┴────────┘
                    ↑
                 (lixo, mas ignorado)
```

**IMPORTANTE:** O valor 3 ainda está na memória, mas é ignorado porque `topo = 1`. Quando fizer próximo push, será sobrescrito.

---

## 🔧 PILHA DINÂMICA: Análise Detalhada

### **Estrutura de Dados**
```c
struct pessoa {
    int senha;          // Dado armazenado
    struct pessoa* prox; // Ponteiro para próximo
};

typedef struct pessoa Pessoa;
Pessoa* topo = NULL;  // Ponteiro para o topo
```

### **Representação na Memória**
```
Stack (pilha):
┌──────────┐
│   topo   │ = NULL  ← Pilha vazia
└──────────┘

Heap (vazio):
[Nenhum nó alocado ainda]
```

---

## 🎬 ANIMAÇÃO: Push Dinâmico (3 elementos)

### **Estado Inicial: Pilha Vazia**
```
main():
┌──────────┐
│   topo   │ = NULL
└──────────┘
```

---

### **1º PUSH: push(1)**

#### **Passo 1: Criar novo nó**
```c
Pessoa* novo = (Pessoa*)malloc(sizeof(Pessoa));
novo->senha = 1;
```

**Memória Heap:**
```
┌──────────────────┐
│  Endereço 0x1000 │
├──────────────────┤
│  senha = 1       │
│  prox = ???      │ ← Ainda não inicializado
└──────────────────┘
```

#### **Passo 2: Conectar ao topo antigo**
```c
novo->prox = topo;  // novo->prox = NULL
```

**Agora:**
```
┌──────────────────┐
│  0x1000          │
├──────────────────┤
│  senha = 1       │
│  prox = NULL     │ ← Fim da pilha
└──────────────────┘
```

#### **Passo 3: Atualizar topo**
```c
topo = novo;  // topo = 0x1000
```

**Resultado:**
```
main():
┌──────────┐        Heap:
│   topo   │───────→┌──────────────────┐
│ 0x1000   │        │  0x1000          │
└──────────┘        ├──────────────────┤
                    │  senha = 1       │
                    │  prox = NULL     │
                    └──────────────────┘
                         BASE/TOPO
```

---

### **2º PUSH: push(2)**

#### **Passo 1: Criar novo nó**
```c
Pessoa* novo = malloc(sizeof(Pessoa));
novo->senha = 2;
```

**Heap agora tem 2 nós:**
```
┌──────────────────┐    ┌──────────────────┐
│  0x1000          │    │  0x2000 (novo)   │
├──────────────────┤    ├──────────────────┤
│  senha = 1       │    │  senha = 2       │
│  prox = NULL     │    │  prox = ???      │
└──────────────────┘    └──────────────────┘
```

#### **Passo 2: Conectar novo ao topo antigo**
```c
novo->prox = topo;  // novo->prox = 0x1000
```

**Agora:**
```
┌──────────────────┐    ┌──────────────────┐
│  0x1000          │←───│  0x2000          │
├──────────────────┤    ├──────────────────┤
│  senha = 1       │    │  senha = 2       │
│  prox = NULL     │    │  prox = 0x1000   │
└──────────────────┘    └──────────────────┘
     BASE                     NOVO
```

#### **Passo 3: Atualizar topo**
```c
topo = novo;  // topo = 0x2000
```

**Resultado:**
```
main():
┌──────────┐
│   topo   │───┐
│ 0x2000   │   │
└──────────┘   │
               ↓
        ┌──────────────┐    ┌──────────────┐
        │  0x2000      │───→│  0x1000      │
        ├──────────────┤    ├──────────────┤
        │  senha = 2   │    │  senha = 1   │
        │  prox = ●    │    │  prox = NULL │
        └──────────────┘    └──────────────┘
            TOPO                 BASE
```

---

### **3º PUSH: push(3)**

**Após mesmo processo:**
```
main():
┌──────────┐
│   topo   │───┐
│ 0x3000   │   │
└──────────┘   │
               ↓
     ┌──────────────┐    ┌──────────────┐    ┌──────────────┐
     │  0x3000      │───→│  0x2000      │───→│  0x1000      │
     ├──────────────┤    ├──────────────┤    ├──────────────┤
     │  senha = 3   │    │  senha = 2   │    │  senha = 1   │
     │  prox = ●    │    │  prox = ●    │    │  prox = NULL │
     └──────────────┘    └──────────────┘    └──────────────┘
         TOPO                                      BASE
```

---

## 🎬 ANIMAÇÃO: Pop Dinâmico

### **Estado Antes do POP**
```
     TOPO
       ↓
     ┌──────────────┐    ┌──────────────┐    ┌──────────────┐
     │  0x3000      │───→│  0x2000      │───→│  0x1000      │
     ├──────────────┤    ├──────────────┤    ├──────────────┤
     │  senha = 3   │    │  senha = 2   │    │  senha = 1   │
     └──────────────┘    └──────────────┘    └──────────────┘
```

### **Executando pop()**

#### **Passo 1: Verificar se está vazia**
```c
if(topo == NULL){  // 0x3000 == NULL? NÃO
    printf("Pilha vazia!\n");
}
```

#### **Passo 2: Guardar referência do topo**
```c
Pessoa* aux;
aux = topo;  // aux = 0x3000
```

**Visualização:**
```
     TOPO           aux
       ↓             ↓
     ┌──────────────┐    ┌──────────────┐    ┌──────────────┐
     │  0x3000      │───→│  0x2000      │───→│  0x1000      │
     ├──────────────┤    ├──────────────┤    ├──────────────┤
     │  senha = 3   │    │  senha = 2   │    │  senha = 1   │
     └──────────────┘    └──────────────┘    └──────────────┘
```

#### **Passo 3: Mover topo para o próximo**
```c
topo = topo->prox;  // topo = 0x2000
```

**Agora:**
```
                    TOPO (novo)
     aux              ↓
       ↓        ┌──────────────┐    ┌──────────────┐
     ┌──────────────┐    │  0x2000      │───→│  0x1000      │
     │  0x3000      │───→├──────────────┤    ├──────────────┤
     ├──────────────┤    │  senha = 2   │    │  senha = 1   │
     │  senha = 3   │    └──────────────┘    └──────────────┘
     └──────────────┘
      (desconectado)
```

#### **Passo 4: Imprimir e liberar**
```c
printf("Senha %d foi retirada\n", aux->senha);
// Imprime: Senha 3 foi retirada

free(aux);  // Libera 0x3000 da memória
```

**Resultado Final:**
```
     TOPO
       ↓
     ┌──────────────┐    ┌──────────────┐
     │  0x2000      │───→│  0x1000      │
     ├──────────────┤    ├──────────────┤
     │  senha = 2   │    │  senha = 1   │
     └──────────────┘    └──────────────┘

O nó 0x3000 foi DELETADO da memória
```

---

## 📊 Comparação Lado a Lado

### **PUSH: Estática vs Dinâmica**

| **Operação** | **Pilha Estática** | **Pilha Dinâmica** |
|--------------|-------------------|-------------------|
| Verificar cheio/vazio | `topo == TAM-1` | `topo == NULL` |
| Alocar espaço | Já alocado (array) | `malloc()` |
| Atualizar índice | `topo++` | `topo = novo` |
| Complexidade | O(1) | O(1) |
| Memória | Fixa | Sob demanda |

### **POP: Estática vs Dinâmica**

| **Operação** | **Pilha Estática** | **Pilha Dinâmica** |
|--------------|-------------------|-------------------|
| Verificar vazio | `topo == -1` | `topo == NULL` |
| Remover | Apenas `topo--` | `topo = topo->prox` |
| Liberar memória | Não precisa | `free(aux)` |
| Complexidade | O(1) | O(1) |

---

## 💡 Conceitos Importantes

### **1. LIFO (Last In, First Out)**
```
PUSH(1) → PUSH(2) → PUSH(3) → POP() → retorna 3
                                       (último que entrou)
```

### **2. Topo da Pilha**
- **Estática:** Índice do array (`int topo`)
- **Dinâmica:** Ponteiro para nó (`Pessoa* topo`)

### **3. Pilha Vazia**
- **Estática:** `topo == -1`
- **Dinâmica:** `topo == NULL`

### **4. Pilha Cheia**
- **Estática:** `topo == TAM - 1`
- **Dinâmica:** Quando `malloc()` retorna NULL (sem memória)

---

## 🎓 Exercícios Propostos

### **Nível Iniciante:**
1. Implemente função `peek()` que retorna o valor do topo sem remover
2. Implemente função `size()` que conta quantos elementos tem na pilha
3. Implemente função `clear()` que remove todos os elementos

### **Nível Intermediário:**
4. Implemente pilha dinâmica com **limite máximo** (resposta à pergunta do código)
5. Crie função `print_reverse()` que imprime da BASE para o TOPO
6. Implemente verificador de parênteses balanceados usando pilha

### **Nível Avançado:**
7. Implemente calculadora de expressões pós-fixadas (RPN)
8. Crie sistema de undo/redo usando 2 pilhas
9. Implemente conversor de decimal para binário usando pilha

---

## 🔍 Gabarito: Exercício 4 (Pilha Dinâmica com Limite)

```c
#define MAX_SIZE 100  // Limite máximo
int contador = 0;      // Contador de elementos

void push(int senha){
    // Verificar se atingiu o limite
    if(contador >= MAX_SIZE){
        printf("Pilha cheia! (Limite: %d)\n", MAX_SIZE);
        return;
    }
    
    Pessoa* novo = (Pessoa*)malloc(sizeof(Pessoa));
    
    if(novo == NULL){
        printf("Erro: Sem memória disponível!\n");
        return;
    }
    
    novo->senha = senha;
    novo->prox = topo;
    topo = novo;
    
    contador++;  // Incrementa contador
    
    printf("Pessoa %d adicionada. Total: %d/%d\n", 
           senha, contador, MAX_SIZE);
}

void pop(){
    if(topo == NULL){
        printf("Pilha vazia!\n");
        return;
    }
    
    Pessoa* aux = topo;
    topo = topo->prox;
    
    printf("Senha %d removida. ", aux->senha);
    
    free(aux);
    
    contador--;  // Decrementa contador
    
    printf("Restam: %d/%d\n", contador, MAX_SIZE);
}
```

---

## 🌟 Aplicações Práticas de Pilhas

### **1. Sistema Operacional - Call Stack**
```
main() chama funcaoA()
funcaoA() chama funcaoB()
funcaoB() chama funcaoC()

Stack:
┌────────────┐
│ funcaoC()  │ ← Executando
├────────────┤
│ funcaoB()  │ ← Pausada
├────────────┤
│ funcaoA()  │ ← Pausada
├────────────┤
│ main()     │ ← Pausada
└────────────┘
```

### **2. Navegador - Histórico**
```
Visitou: Google → YouTube → GitHub → Stack Overflow

Pilha:
┌──────────────────┐
│ Stack Overflow   │ ← Página atual
├──────────────────┤
│ GitHub           │
├──────────────────┤
│ YouTube          │
├──────────────────┤
│ Google           │
└──────────────────┘

Botão "Voltar" = POP
```

### **3. Editor de Texto - Ctrl+Z**
```
Ações:
1. Digitou "Hello"
2. Digitou " World"
3. Deletou "World"
4. Digitou " Universe"

Pilha Undo:
┌────────────────────┐
│ Digitou "Universe" │ ← Último
├────────────────────┤
│ Deletou "World"    │
├────────────────────┤
│ Digitou " World"   │
├────────────────────┤
│ Digitou "Hello"    │
└────────────────────┘

Ctrl+Z = POP da pilha
```

### **4. Verificador de Parênteses**
```
Entrada: "((a + b) * (c - d))"

Processo:
( → PUSH
( → PUSH
) → POP (match!)
) → POP (match!)

Se pilha vazia no final = balanceado ✓
Se sobrou algo na pilha = desbalanceado ✗
```

### **5. Calculadora RPN (Notação Polonesa Reversa)**
```
Expressão: 3 4 + 5 *
(Normal seria: (3 + 4) * 5 = 35)

Processo:
3 → PUSH(3)
4 → PUSH(4)
+ → POP(4), POP(3), PUSH(7)
5 → PUSH(5)
* → POP(5), POP(7), PUSH(35)

Resultado: 35
```

---

## ⚠️ Erros Comuns e Como Evitar

### **Erro 1: Esquecer de verificar pilha vazia no POP**
```c
❌ ERRADO:
void pop(){
    topo--;  // Se topo já é -1, vira -2!
}

✅ CORRETO:
void pop(){
    if(topo == -1){
        printf("Pilha vazia!\n");
        return;
    }
    topo--;
}
```

### **Erro 2: Esquecer de liberar memória (pilha dinâmica)**
```c
❌ ERRADO:
void pop(){
    topo = topo->prox;  // Perdeu referência, vazamento de memória!
}

✅ CORRETO:
void pop(){
    Pessoa* aux = topo;
    topo = topo->prox;
    free(aux);  // SEMPRE liberar!
}
```

### **Erro 3: Não verificar malloc()**
```c
❌ ERRADO:
Pessoa* novo = malloc(sizeof(Pessoa));
novo->senha = 10;  // E se malloc retornou NULL?

✅ CORRETO:
Pessoa* novo = malloc(sizeof(Pessoa));
if(novo == NULL){
    printf("Erro: sem memória!\n");
    return;
}
novo->senha = 10;
```

### **Erro 4: Confundir ordem LIFO**
```c
// PUSH: 1, 2, 3
// POP retorna: 3 (não 1!)

┌───┐
│ 3 │ ← Topo (sai primeiro)
├───┤
│ 2 │
├───┤
│ 1 │ ← Base (sai por último)
└───┘
```

---

## 📝 Resumo dos Conceitos-Chave

✅ **Pilha** = LIFO (Last In, First Out)  
✅ **PUSH** = Adiciona no topo  
✅ **POP** = Remove do topo  
✅ **Estática** = Array com tamanho fixo  
✅ **Dinâmica** = Lista encadeada flexível  
✅ **Topo** = Índice (estática) ou Ponteiro (dinâmica)  
✅ **Vazia** = `topo == -1` ou `topo == NULL`  
✅ **Cheia** = `topo == TAM-1` (só estática)  

---

## 🎯 Quando Usar Pilha?

**Use pilha quando:**
- Precisa do último elemento adicionado
- Implementar undo/redo
- Processar expressões matemáticas
- Verificar balanceamento (parênteses, tags HTML)
- Implementar recursão de forma iterativa
- Navegação (voltar/avançar)

**NÃO use pilha quando:**
- Precisa acessar elementos do meio
- Ordem de saída deve ser FIFO (use fila)
- Precisa buscar elemento específico
- Acesso aleatório é necessário (use array/lista)

---

**Pratique muito! Desenhe as pilhas, faça push e pop no papel antes de codificar.** 🎨

**Próximos passos:** Estude **Filas** (FIFO), que são o complemento das Pilhas! 🚀
