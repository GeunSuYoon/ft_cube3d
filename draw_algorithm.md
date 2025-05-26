# Draw Alogrithm

## Draw Line

### Bresenham's Line Algorithm

[SRC](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)

- 미니맵의 가운데(플레이어의 위치)를 저장한다. $(x_0,\ y_0)$
- 플레이어가 보고 있는 방향의 끝점을 저장한다. $(x_1,\ y_1)$
- 두 좌표의 차이값을 계산한다. $(d_x,\ d_y)$
- 그릴 때 나아갈 방향을 결정한다. $(s_x,\ s_y)$
- 지금 그리려는 위치와 실제 그려야 하는 위치의 오차를 저장한다. $err\ =\ d_x\ +\ d_y$
  - 해당 값은 x값 변화량에 따른 y값의 오차이다.
- 점을 찍은 뒤, ```err``` 값의 2배를 ```dx, dy```와 비교하며 $(x_0,\ y_0)$ 값에 $s_x$ 혹은 $s_y$를 더할지 결정하고, 더한다면 ```err``` 값에 ```dx``` 혹은 ```dy```를 더해준다.
- $x_0\ =\ x_1,\ y_0\ =\ y_1$이 될때까지 이 과정을 반복한다.

## Draw Circle

- 0부터 44까지 돌며 각도를 맞춘다. $angle\ =\ [0,\ 45)$
- $x\ =\ cos(angle)\ *\ PPIXEL,\ y\ =\ sin(angle)\ *\ PPIXEL$로 설정한다.
- 미니맵의 가운데를 기준으로 $(x,\ y)$좌표를 8방향 찍어준다. $(+-x,\ +-y)$, $(+-y,\ +-x)$
