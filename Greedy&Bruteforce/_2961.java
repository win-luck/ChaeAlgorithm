import java.util.*;

public class Main {
	public static int n;
	public static int[][] taste;
	// 왼쪽 열은 신맛(곱), 오른쪽 열은 쓴맛(합)
	public static boolean[] visit;
	// 재료의 선택 여부를 담은 배열
	public static int result;

	public static void MakeFood(int index) {
		if(index == n) { // 모든 재료의 사용 여부를 결정했다면
			// (인자가 0~n-1까지 유효하므로 index가 n이 되면 모든 재료 탐색 끝난 상태)
			int sin = 1; // 신맛
			int ssn = 0; // 쓴맛
			
			for(int i=0; i<n; i++) {
				if(visit[i]) { // 이 인덱스의 재료를 선택했을 때만 진행
					sin *= taste[i][0]; // 신맛은 곱
					ssn += taste[i][1]; // 쓴맛은 합
				}
			}
			
			// 이 두 값의 차이가 가장 작은 경우를 찾아내야 함.			
			if(sin!=1 && ssn!=0 && result > Math.abs(sin-ssn)) {
				// 초기 두 조건은 아무것도 선택하지 않는 경우를 배제하기 위함.
				// 마지막 조건이 작은 경우를 찾아내서 갱신하는 역할
				result = Math.abs(sin-ssn);
			}
			return; // 아래로 넘어가면 안 됨
		}
		
		visit[index] = true; // 현재 인덱스의 재료가 선택된 상태에서
		MakeFood(index+1);  // 다음 재료에 대한 판단으로 이동
		visit[index] = false; // 선택하지 않은 상태에서
		MakeFood(index+1); // 다음 재료에 대한 판단으로 이동
	}
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  
        n = sc.nextInt();
        result = Integer.MAX_VALUE;
        visit = new boolean[n];
        taste = new int[n][2];
        
        for(int i=0; i<n; i++) {
        	taste[i][0] = sc.nextInt();
        	taste[i][1] = sc.nextInt();
        }
        
        MakeFood(0);
        System.out.println(result);
    }
    
}