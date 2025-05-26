# Flow

- 전체적인 코드의 흐름을 설명한다.

## 흐름

- 프로그램 인자 format 검사
- game structure 초기화
  - mlx_ctl structure 초기화
  - window image structure 초기화
  - image container structure 초기화
    - image structure 초기화
  - color 초기화
  - player structure 초기화
  - map structure 초기화
    - minimap structure 초기화
- mlx_loop_hook
  - ray casting
  - window에 띄우기
  - 키 입력에 따른 player 인자 변경

## 프로그램 인자 검사

- 프로그램 인자가 2개인지 아닌지 검사한다. \($프로그램명 $맵파일)
- 맵파일의 첫 이름이 '.'인지 아닌지 검사한다.
  - 숨김파일일 수 있지만, 명령어\(touch, cat 등등)로 만들지 않은 파일의 경우 sh파일 등으로 인식한다.
- 확장자가 cub인지 아닌지 검사한다.
- 맵 파일이 열 수 있는지 검사한다.
- 맵 파일의 fd를 반환한다.
- 이후 언급하는 fd는 따로 말이 없다면 여기서 연 맵 파일의 fd이다.

## game structure 초기화

- game structure는 프로그램 실행에 필요한 모든 정보를 담고 있는 최상위 structure다.
- game structure 내부에 연결된 모든 structure를 초기화하는 역할을 한다.
- game structure를 메모리에 할당한다.
- 이후 필요한 경우 각 structure에 맵 fd를 인자로 보내준다.

## mlx_ctl structure 초기화

- mlx_ctl structure를 메모리에 할당한다.
- mlx를 ```mlx_init``` 함수를 이용해 초기화한다.
- win을 ```mlx_new_window``` 함수를 이용해 초기화한다.

## window image structure 초기화

- ray casting 결과를 담아낼 image structure를 초기화한다.
- image structure를 메모리에 할당한다.
- ```mlx_new_image``` 함수와 ```mlx_get_data_addr``` 함수를 이용해 image structure의 요소를 초기화한다.

## image container structure 초기화

- 4 방향의 벽 texture 정보를 저장할 4개의 image structure를 저장하는 structure다.
- image container structure를 메모리에 할당한다.

## image structure 초기화

- xpm 파일을 읽어 저장하는 structure이다.
- 맵 파일 fd를 받아 한 줄씩 읽으며 정보를 저장한다.
- image structure를 메모리에 할당한다.
- ```mlx_xpm_file_to_image``` 함수를 이용해 xpm 파일을 이미지로 저장한다.
- 만일 오류가 생기면 에러 메시지를 출력한 뒤 exit한다.
- 저장한 이미지를 ```mlx_get_data_addr``` 함수를 이용해 파일 이미지를 데이터로 저장한다.
- 이후 image resizer 함수를 이용해 정의한 SIZE 크기로 이미지를 조정한다.

## color 초기화

- window에 보여줄 천장과 바닥의 색상을 저장한다.
- format에 맞지 않으면 에러 메시지를 출력한 뒤 exit한다.

## player structure 초기화

- player의 위치, 방향 정보를 담은 structure이다.
- player structure를 메모리에 할당한다.
- 내부 인자 초기화는 map structure 초기화에서 담당한다.

## map structure 초기화

- map과 관련된 데이터를 담은 structure이다.
- map structure를 메모리에 할당한다.
- fd를 이용해 파일을 한 줄씩 읽어 부적절한 simbol이 있는지 확인한다.
- 다 읽은 후 한 줄씩 읽으며 2차원 int 배열을 이용해 나머지 validation 검사를 실시한다.
  - 만일 player 심볼을 발견한다면 player structure의 위치, 방향 정보를 초기화한다.
  - 이미 player의 정보가 초기화되어있다면 에러 메시지를 띄우고 exit한다.
- player의 초기 위치를 기준으로 dfs로 player가 빈 공간에 도달할 수 있는지 없는지 확인한다.
- player가 직접 이동할 수 있는 공간을 기준으로 map을 optimize한다.

## minimap structure 초기화

- 실제 window에 띄워줄 미니맵에 활용할 여러 값들을 저장한다.
- minimap structure를 메모리에 할당한다.
- scale과 미니맵의 시작 위치를 저장한다.

## mlx_loop_hook

- ```cast_window``` 함수를 인자로 받아 ray casting을 계속 실행한다.

## ray casting

[참조 문헌](https://lodev.org/cgtutor/raycasting.html)

- 누르고 있는 키에 맞춰 player의 위치나 방향을 변경한다.
- 현재 보여주고 있는 window를 초기화한다.
- 상단 문헌을 참고해 dda 알고리즘으로 ray casting을 실행한 결과를 window image에 저장한다.
- 현재 플레이어 위치를 중앙으로 하여 map의 정보를 minimap을 이용해 window image에 저장한다.
- 새로운 window image를 실제 창에 띄운다.

## 키 입력에 따른 player 인자 변경

- WASD, 왼쪽 오른쪽 방향키, SHIFT 키를 눌리고 있으면 해당 정보를 업데이트 한다.
- 위에 해당하는 키를 뗀다면 해당 정보를 업데이트 한다.
