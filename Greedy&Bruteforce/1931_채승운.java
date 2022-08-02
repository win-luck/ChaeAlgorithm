import java.util.*;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);    
        int n = sc.nextInt();
        int[][] arr = new int[n+1][2];
        
        for(int i=1; i<=n; i++) {
        	arr[i][0] = sc.nextInt();
        	arr[i][1] = sc.nextInt();
        } // 입력
        
        Arrays.sort(arr, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				if(o1[1] == o2[1]) { // 종료시간이 같으면
					return o1[0]-o2[0]; // 시작시간 오름차순
				} else {
					return o1[1]-o2[1]; // 종료시간 오름차순
				}
			}
        });
        
        int count = 1;
        int start = arr[1][0];
    	int end = arr[1][1]; // 최초 강의실 대여 시작
                
        for(int i=2; i<=n; i++) {
        	if(arr[i][0]>=end) { // 다음 수업의 시작시간>=현재 수업의 종료시간이라면 조건에 부합함
        		end = arr[i][1]; // 다음 수업으로 갱신
        		count++; // 개수 추가
        	}	     	
        }
        
        System.out.println(count);
    } 
}