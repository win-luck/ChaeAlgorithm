import java.util.*;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);    
        int n = sc.nextInt();
       	int[][] time = new int[n+1][2];
        
        for(int i=1; i<=n; i++) {
        	time[i][0] = sc.nextInt();
        	time[i][1] = sc.nextInt();
        } // 입력
        
        Arrays.sort(time, new Comparator<int[]>(){

			@Override
			public int compare(int[] o1, int[] o2) {
				// TODO Auto-generated method stub
				if(o1[0] == o2[0]) {
					return o1[1] - o2[1];
				} else {
					return o1[0] - o2[0];
				}
			}       	
        }); // 시작시간 기준 오름차순 정렬, 동일하면 종료시간 기준 오름차순 정렬
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.add(time[1][1]);
        // 우선순위 큐에는 종료시간이 오름차순으로 들어간다.
        
        for(int i=2; i<=n; i++) {
        	if(time[i][0] >= pq.peek()) {
        		pq.poll();
        	}
        	// 현재 강의의 시작시간이 우선순위 큐의 종료 시간보다 크거나 같다면, 새 강의실이 필요없기에 종료시간을 갱신한다.
        	//  만약 작다면 종료시간과 충돌하므로 새로운 강의실을 추가하고 그 종료시간을 삽입한다.       	
        	pq.add(time[i][1]);
        } 
        
        System.out.println(pq.size());
        // 우선순위 큐의 크기가 필요 강의실의 개수가 된다.
    } 
}