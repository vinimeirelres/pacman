# Pac-Man

Implementação simplificada do clássico **Pac-Man** em **C++** com uso da biblioteca **Allegro 5**, desenvolvida como parte da disciplina **SIN141 – Computação Orientada a Objetos**, na **Universidade Federal de Viçosa – Campus Rio Paranaíba**.

---

## Colaboradores

- Vinícius Meireles Pereira Santos
- Luiz Benedito Alves Neto  
- Mariana de Deus Castro  

---

## Visão Geral

Este projeto traz uma versão funcional do jogo Pac-Man, adaptado com personagens personalizados (“PacMario”) e foco nos fundamentos de orientação a objetos.  
A implementação inclui movimentação do jogador, coleta de pílulas e sistema de pontuação.

> A versão atual é funcional, porém **incompleta**:
- Ainda não há fantasmas ou menu de início.
- O destrutor da classe `PacMario` tenta deletar um mapa não alocado dinamicamente.
- O timer é criado incorretamente com valor `60` em vez de `1.0/60` (para 60 FPS).

---

## Estrutura de Arquivos

- `Main.cpp` – Ponto de entrada do jogo  
- `pacmario.cpp` / `pacmario.h` – Classe do jogador (movimentação, placar)  
- `mapa.cpp` / `mapa.h` – Estrutura e layout do labirinto  
- `paredes.cpp`, `pilulas.cpp`, `piso.cpp` – Elementos do cenário  
- `blocos.png`, `pcmr.png` – Recursos gráficos (paredes, personagem)  
- `arial.ttf` – Fonte usada na pontuação

---

## Requisitos

- C++ (compilador compatível com C++11 ou superior)  
- Allegro 5 com os módulos:
  - `allegro`
  - `allegro_image`
  - `allegro_font`
  - `allegro_ttf`
  - `allegro_primitives`

---

## Como Compilar

### Via Visual Studio
Crie um novo projeto C++ no Visual Studio e adicione todos os arquivos `.cpp` e `.h` do projeto. 
Certifique-se de configurar corretamente os diretórios das bibliotecas Allegro 5 nas propriedades do projeto.

### Via terminal (Linux):
```bash
g++ Main.cpp pacmario.cpp paredes.cpp pilulas.cpp piso.cpp mapa.cpp \
    -o Pac-Man \
    `pkg-config --libs allegro-5 allegro_font-5 allegro_ttf-5 \
    allegro_image-5 allegro_primitives-5`
```

---

## Como Executar

Após a compilação, certifique-se de que os arquivos de recursos (`blocos.png`, `pcmr.png`, `arial.ttf`) estejam **no mesmo diretório** que o executável.

Execute no terminal:

```bash
./Pac-Man
```

---

## Observações Finais

Apesar de simplificada, a aplicação demonstra conceitos importantes de:
- Orientação a Objetos em C++
- Manipulação gráfica com Allegro 5
- Desenvolvimento de jogos 2D
