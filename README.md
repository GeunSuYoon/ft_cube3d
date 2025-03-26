# ft_cube3d

## Mandatory

---

- Program name: cub3D
- Turn in files: All your files
- Makefile: all, clean, fclean, re, bonus
- Arguments: a map in format *.cub
- External functs
  - open, close, read, write, printf, malloc, free, perror, strerror, exit, gettimeofday
  - All functions of the math library\(-lm man man 3 math)
  - All functions of the MinilibX
- Libft authorized: Yes
- Description: You must create a “realistic” 3D graphical representation of the inside of a maze from a first-person perspective. You have to create this representation using the Ray-Casting principles mentioned earlier.

---

### Constratint

- **miniLibX**를 사용해야만 한다.
- 프로그램의 윈도우는 부드럽게 작동해야 한다.
  - 다른 윈도우를 키거나 최소화 하거나 등등...
- 벽의 동서남북 방향에 따라 다른 texture를 보여줘야 한다.
- 천장과 바닥을 다른 색으로 설정할 수 있어야 한다.

### Program display rule

- 키보드의 좌우 화살표를 누르면 미로의 좌우를 볼 수 있어야 한다.
- WASD 키로 움직일 수 있어야 한다.
- ESC를 누르면 윈도우가 닫히고 프로그램이 깔끔히 종료돼야 한다.
- 윈도우 바의 빨간 x키를 누르면 윈도우가 닫히고 프로그램이 깔끔히 종료돼야 한다.
- ```miniLibX```의 ```image``` 사용을 강력히 추천한다.

### Map rule

- map file의 확장자는 .cub이어야 한다.
- map은 6개의 character로만 이루어져있다.
  - 0: empty space
  - 1: Wall
  - N, S, E, W: player's start position and spawning orientation
- map은 벽으로 둘러쌓여있어야 하며, 그렇지 않을 경우 error를 반환한다.
- map content 이외에 각 요소들은 하나 이상의 빈 줄로 분리될 수 있다.
- 항상 마지막에 있어야 하는 map content를 제외하고, 각 요소는 어떤 순서로든 설정할 수 있다.
- map을 제외하고 각 유형의 정보는 하나 이상의 빈칸으로 분리될 수 있다.
- map은 file에 표시된 대로 구문을 분석해야 한다.
- 공백은 map의 유효한 부분이며 사용자가 처리할 수 있다.
- 지도의 규칙을 준수하는 한 모든 종류의 지도를 분석할 수 있어야 한다.
- map을 제외한 각 요소는 type identifier 이후 정보를 담고 있어야 한다. 이하는 예시이다.
  - North texture: NO ./path_to_texture
    - identifier: NO
    - path to texture
  - South texture: SO ./path_to_texture
    - identifier: SO
    - path to texture
  - West texture: WE ./path_to_texture
    - identifier: WE
    - path to texture
  - East texture: EA ./path_to_texture
    - identifier: EA
    - path to texture
  - Floor color: F 220,100,0
    - identifier: F
    - RGB in range\[0,255]: 220, 100, 0
  - Ceiling color: C 255,30,0
    - identifier: C
    - RGB in range\[0,255]: 255, 30, 0


















