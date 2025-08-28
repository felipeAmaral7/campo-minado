# campo-minado

# 🎮 Campo Minado em C

Um simples jogo de **Campo Minado** implementado em C para rodar direto no terminal.  
O jogador deve escolher posições do tabuleiro sem acertar uma bomba 💣.

---

## 📌 Funcionalidades
- Tabuleiro **10x10**.
- **20 bombas** espalhadas aleatoriamente.
- Contagem de bombas vizinhas para ajudar o jogador.
- Expansão automática quando a célula escolhida não tem bombas vizinhas.
- Interface simples direto no terminal.

---

## 🛠️ Como compilar e executar

### Linux / MacOS
No terminal:

gcc campo_minado.c -o campo_minado
./campo_minado

Windows (MinGW)
gcc campo_minado.c -o campo_minado.exe
campo_minado.exe

## Como jogar

O programa mostra o tabuleiro com as células ainda ocultas.

Digite as coordenadas no formato:
linha coluna
3 5

Isso abre a célula na linha 3 e coluna 5.

Se for uma bomba → 💥 Fim de jogo.
Se não for → mostra o número de bombas vizinhas.

Continue até revelar todas as células seguras.
