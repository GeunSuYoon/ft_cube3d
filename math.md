# Math

## Pos

- Player : $(x_p,\ y_p,\ SIZE / 3)$ = $(x_p,\ y_p,\ z_p)$
- Wall : $SIZE\ *\ (x_w,\ y_w,\ 0)\ +\ n\ (0\ <= n\ <\ SIZE)$
- Celling : $SIZE\ *\ (x_c,\ y_c,\ 1\ -\ n)\ +\ n\ (0\ <= n\ <\ SIZE)$
- Floor : $SIZE\ *\ (x_f,\ y_f,\ -n)\ +\ n\ (0\ <= n\ <\ SIZE)$

## Dist

- Let $point_1$ = $(x_1,\ y_1,\ z_1)$, $point_2$ = $(x_2,\ y_2,\ z_2)$
- $d$ = $sqrt((x_1\ - x_2)^{2}\ +\ (y_1\ - y_2)^{2}\ +\ (z_1\ - z_2)^{2})$

## Angle

- Let $direct_p$ = $(dir_x,\ dir_y)$
- $tan\ \theta$ = ${dir_y}/{dir_x}$
- $\theta$ = $tan^{-1}\ ({dir_y}/{dir_x})$
