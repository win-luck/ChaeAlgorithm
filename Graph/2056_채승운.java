import java.util.*;

public class Main {
		
	static int n, max;
	static int[] time = new int[10001]; // 작업의 소요시간 저장
	static int[] indegree = new int[10001]; // 인접차수 저장
	static int[] answer = new int[10001]; // 모든 작업 완료의 최소시간 저장 
	static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
	
	public static void topologySort() {
		Queue<Integer> q = new LinkedList<>(); // 진입차수 0인 노드들을 담아 순서를 만들어낼 큐		
		
		for(int i=1; i<=n; i++) {
			if(indegree[i] == 0) { // 진입차수가 0인 모든 노드들을 일단 큐에 삽입
				q.offer(i);
			}
			answer[i] = time[i]; // 당연히 answer은 자기 자신의 작업시간을 기본적으로 가짐.
		}
		
		while(!q.isEmpty()) { // 계산 과정 도중에 큐가 비면 사이클
			int now = q.poll(); // 큐에서 진입차수 0인 노드 하나를 빼내고			
			
			for(int i=0; i<graph.get(now).size(); i++) { // 현재 노드가 가지고 있는 진출차수의 개수만큼 반복
				int index = graph.get(now).get(i);
				
				if(--indegree[index] == 0) { // 그 노드가 만약 진입차수가 0이 되었다면
					q.offer(index); // 큐에 삽입		
				}
				
				answer[index] = Math.max(answer[index], answer[now] + time[index]);
				// 왜 최소 시간인데 max로 처리하는가? 이전 모든 작업이 수행되지 않았다면 다음 작업이 진행될 수 없음.
				// 즉 이전의 모든 작업이 완료되기 위해서는 최장 거리를 구해야 함.
				//  now는 큐에서 방금 꺼낸 작업이고, index는 now와 연결된 다음 작업
			}
		}
		
		for(int i=1; i<=n; i++) {
			max = Math.max(max, answer[i]); // answer[i]는 i부터 출발했을 때 모든 작업을 완료하기 위한 최소 시간			
		}
		System.out.println(max);
	}
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);         
        n = sc.nextInt(); // 정점의 개수
        
        for(int i=0; i<=n; i++) {
        	graph.add(new ArrayList<Integer>()); // 객체 내부 객체 초기화
        } // 왜 n+1번 초기화하나요? 0번째 인덱스를 사용하지 않기 때문
             
        for(int i=1; i<=n; i++) {
        	time[i] = sc.nextInt(); // i번 작업 진행시간
        	int before = sc.nextInt(); // i번 작업 전 선행되는 작업의 개수
        	
        	for(int j=0; j<before; j++) {
        		int input = sc.nextInt(); // 선행되는 작업의 인덱스 입력
        		graph.get(input).add(i); // 선행되는 작업의 인덱스 리스트에 i 추가
            	indegree[i]++; // i로 화살표가 들어오므로 i의 진입 차수 +1
        	}       	
        }
        
        topologySort(); // 함수 시작
    }
      
}