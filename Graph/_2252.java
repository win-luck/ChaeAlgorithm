import java.util.*;

public class Main {
		
	static int n, m;
	static int[] indegree = new int[100001];
	static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
	
	public static void topologySort() {
		Queue<Integer> q = new LinkedList<>(); // 진입차수 0인 노드들을 담아 순서를 만들어낼 큐
		ArrayList<Integer> result = new ArrayList<>(); // 결과 출력을 위한 리스트
		
		for(int i=1; i<=n; i++) {
			if(indegree[i] == 0) { // 진입차수가 0인 모든 노드들을 일단 큐에 삽입
				q.offer(i);
			}
		}
		
		while(!q.isEmpty()) { // 계산 과정 도중에 큐가 비면 사이클
			int now = q.poll(); // 큐에서 진입차수 0인 노드 하나를 빼내고
			result.add(now); // 결과에 추가
			
			for(int i=0; i<graph.get(now).size(); i++) { // 현재 노드가 가지고 있는 진출차수의 개수만큼 반복
				indegree[graph.get(now).get(i)] -= 1; // 이 노드와 연결된 노드들의 진입차수 -1
				if(indegree[graph.get(now).get(i)] == 0) { // 그 노드가 만약 진입차수가 0이 되었다면
					q.offer(graph.get(now).get(i)); // 큐에 삽입
				}
			}		
		}
		
		for(int i=0; i<result.size(); i++) {
			System.out.print(result.get(i)+ " "); // 결과
		}	
	}
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);         
        n = sc.nextInt(); // 정점의 개수
        m = sc.nextInt(); // 간선의 개수
        
        for(int i=0; i<=n; i++) {
        	graph.add(new ArrayList<Integer>()); // 객체 내부 객체 초기화
        } // 왜 n+1번 초기화하나요? 0번째 인덱스를 사용하지 않기 때문
        
        for(int i=0; i<m; i++) { // 간선의 개수만큼 정점 a와 b를 연결
        	int a = sc.nextInt();
        	int b = sc.nextInt();
        	graph.get(a).add(b); // 인접 리스트 방식으로 연결 상황 반영
        	indegree[b]++; // b로 화살표가 들어오므로 b의 진입 차수 +1
        }
        
        topologySort(); // 함수 시작
    }
    
    
    
    
}