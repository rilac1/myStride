# MyStride

### Usage
#### Compile
```
    make
```
#### Execute
```
    ./mystride
```

### Set Macro
* 헤더파일에서 메크로 수정
    > MAX: 전체 수행해야 할 양.  
    > NUM: 프로세스 수  
* MAX <=40 이면 인터페이스 출력.


### Set mode
> test.c에서 세 가지 모드 골라서 사용.  (주석처리)
> 1. 시뮬레이터  
> 2. 성능측정
> 3. CPU bound vs IO bound 스케줄링 빈도 차이


### New Scheduling Policy_Ad Stride
![image01](https://user-images.githubusercontent.com/67721382/117925842-c6cd1d80-b332-11eb-84a1-ab894d1f770f.png)

### 문맥교환 횟수 비교
![image02](https://user-images.githubusercontent.com/67721382/117926035-14e22100-b333-11eb-98c9-b57ebb330940.png)

### IO bound vs CPU bound
![image03](https://user-images.githubusercontent.com/67721382/117926090-2d523b80-b333-11eb-8cb7-6a31d756443d.png)
