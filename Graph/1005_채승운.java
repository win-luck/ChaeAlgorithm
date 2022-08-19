import java.util.*;

public class Main {
		
	static int n, k, w;
	static int[] time; // 작업의 소요시간 저장
	static int[] indegree; // 인접차수 저장
	static int[] answer; // 모든 작업 완료의 최소시간 저장 
	static ArrayList<ArrayList<Integer>> graph;
	
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
		System.out.println(answer[w]);
	}
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);          
        int testcase = sc.nextInt(); // 테스트케이스
        
        for(int a=0; a<testcase; a++) {
	        n = sc.nextInt(); // 건물의 개수
	        k = sc.nextInt(); // 건물 사이의 관계 개수
	        
	        graph = new ArrayList<ArrayList<Integer>>();
	        time = new int[n+1]; 
	    	indegree = new int[n+1];
	    	answer = new int[n+1]; // 관련 배열 및 리스트 n에 맞춰서 초기화
	        
	        for(int i=0; i<=n; i++) {
	        	graph.add(new ArrayList<Integer>()); // 객체 내부 객체 초기화
	        } // 왜 n+1번 초기화하나요? 0번째 인덱스를 사용하지 않기 때문
	           
	        for(int i=1; i<=n; i++) {
	        	time[i] = sc.nextInt(); // 건물 당 소요시간 입력
	        }
	        
	        for(int i=1; i<=k; i++) {
	        	int start = sc.nextInt(); // i번 작업 진행시간
	        	int end = sc.nextInt();
	       		
	        	graph.get(start).add(end); // 선행되는 작업 start의 인덱스 리스트에 end 추가
	            indegree[end]++; // end로 화살표가 들어오므로 end의 진입 차수 +1	        	       	
	        }
	        w = sc.nextInt(); // 목표 건물
	        
	        topologySort(); // 함수 시작        
        }
        
    }
      
}