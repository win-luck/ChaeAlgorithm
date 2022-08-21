import java.util.*;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);    
        int n = sc.nextInt();
        long[] dis = new long[n];
        long[] gas = new long[n];
        long length = 0;
        
        for(int i=1; i<=n-1; i++) {
        	dis[i] = sc.nextLong();
        	length+=dis[i]; // 총 거리를 저장하기 위함
        }        
        for(int i=1; i<=n-1; i++) {
        	gas[i] = sc.nextLong();
        }
        
        long trash = sc.nextLong(); // 마지막 주유소는 필요없는 값임
        
        long sum = 0;
    	long gaspoint = gas[1]; // 최초 주유소
    	
        for(int i=1; i<=n-1; i++) {
        	if(gaspoint>gas[i]) { // 만약 현재 주유소가 이전 주유소보다 싸다면
        		gaspoint = gas[i]; // 싼 주유소로 갱신한다. 이 경우 최소 비용을 얻을 수 있다.
        	}
        	sum += dis[i]*gaspoint; // dis[i]만큼의 거리를 gaspoint만큼 이동한 가격이 담김
        	length -= dis[i]; // dis[i]만큼 거리를 이동했으므로 깎아준다.
	
           	if(length == 0) { // 끝까지 도달한 경우 반복문 종료
           		break;
           	}   	
        }
        	  
        System.out.println(sum);     
    } 
}