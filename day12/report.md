# 자료구조 구현 보고서

## 링크드 리스트
- 노드를 저장할때 노드에 다음 노드의 위치와 데이터를 포함시켜 자료를 저장하는 방식.
- 단순 링크드 리스트는 다음 노드의 위치와 데이터로 이루어져있음.
- 이중 링크드 리스트는 다음 노드의 위치와 이전 노드의 위치, 데이터로 이루어져있음.
- 배열에 비해 데이터의 중간 삽입,삭제가 쉽고 빠르다.
- 하지만 배열은 인덱스만 주어지면 바로 주소를 계산해 접근할수 있는 반면, 링크드 리스트는 노드를 찾아야 하기때문에 탐색 속도가 느리다.(단순 링크드리스트)

![linkedlist](http://algorithms.tutorialhorizon.com/files/2016/03/Doubly-Linked-List.png)

## 큐
- 선입 선출(FIFO) 구조로 데이터를 저장하는 방식.
- Rear(또는 back)에서 데이터가 들어오고 Front에서 데이터가 나간다.

![queue](https://upload.wikimedia.org/wikipedia/commons/thumb/5/52/Data_Queue.svg/1200px-Data_Queue.svg.png)

### 원형 큐
- 배열을 이용해서 큐를 구현하는 방법.
- 배열의 끝과 시작 부분이 서로 연결되어 있다고 가정한다.
- 큐가 비어있을때는 front == rear이다.
- 큐가 가득 차있을때는 (rear + 1) % size == rear이다.