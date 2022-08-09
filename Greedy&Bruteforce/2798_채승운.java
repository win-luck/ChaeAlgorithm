import java.util.*;

public class Main {
	public static int n,m;
	public static int[] arr;
	
	public static int BlackJack(int[] arr) {
		int max = -1;
		int sum = 0;
		
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				for(int k=j+1; k<n; k++) {
					sum = arr[i]+arr[j]+arr[k];
					// BruteForce 알고리즘을 적용하는 3중 for문
					if(sum>max && sum<=m) { // m보다 크지 않으면서 기존 최댓값보다 크면 최댓값을 갱신해줌.
						max = sum;
					}
				}
			}
		}
		
		return max;
	}
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  
        n = sc.nextInt();
        m = sc.nextInt();
        // 카드의 합이 m을 넘지 않으면서 m과 가장 가까워야 하고, 그 값을 출력 
        arr = new int[n];
        
        for(int i=0; i<n; i++) {
        	arr[i] = sc.nextInt();
        }
        
        System.out.println(BlackJack(arr));
    }
    
}