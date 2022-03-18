​
cycle 판단 문제는

시작점이 될수 있는 노드들을 dfs 돌린다.

돌릴때, 각 노드들에 대하여 상태값을 3가지로 줘야한다.

1.한번 돌렸을때 cycle이 없다고 판단되면 -> 재귀를 빠져나오며 더이상 검사할 필요가 없다는 의미의 2를 부여

2.해당 노드가 한번도 방문한 적이 없다는 의미의 0 (초기값)

3.해당 노드는 한번의 dfs에서 방문 중인 노드라는 1을 부여

--------------------------------------------------------------------------------------------------------------------------------------------------

example)

A노드 ----> B노드 <---- C노드가 있다고 치자.

A, B, C 순으로 bfs를 돌린다고 치자

A노드에서 dfs : A노드와 B노드를 방문하고 나온다.

B노드는 adj에서 start 노드가 아니기에 패스

C노드에서 dfs : "2"라는 개념이 없다면 1로 이미 방문했던 노드라 판단하고 cycle이라고 나와버린다.

-> 그래서 2라는 개념을 도입하면, C노드를 방문후 B를 방문하였을 때, B노드 부터는 더이상 방문하지 않아도 되구나! + cycle이 없구나! 라고 판단 할 수 있게 된다.