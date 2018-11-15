import java.util.Scanner;

public class ccc00j3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		int slot1 = 1;
		int slot2 = 0;
		int slot3 = 0;
		boolean wait = false;
		
		int Mjar = sc.nextInt();
		int fmac = sc.nextInt();
		int fmacorin = 35;
		int smac = sc.nextInt();
		int smacorin = 100;
		int tmac = sc.nextInt();
		int tmacorin = 10;
		
		for(int i = 0; i < 10000; i ++) {
		
			if(fmac != 0) {
				if(slot2 == 1) {
					if(fmac % fmacorin == 0) {
						Mjar = Mjar + 30;
						fmac = 0;
					}
				}
			}
			if(smac != 0) {
				if(slot3 == 1) {
					if(smac % smacorin == 0) {
						Mjar = Mjar + 60;
						smac = 0;
					}
				}
			}
			if(tmac != 0) {
				if(slot1 == 1) {
					if(tmac % tmacorin == 0) {
						Mjar = Mjar + 9;
						tmac = 0;
					}
				}
			}
			
			if(Mjar == 0) {
				System.out.println("Martha plays " + i + " times before going broke.");
				return;
			}
			
			if(wait == false) {
				if(slot1 == 1) {
					fmac = fmac + 1;
					slot1 = 0;
					slot2 = 1;
					wait = true;
				}
			}
			if(wait == false) {
				if(slot2 == 1) {
					smac = smac + 1;
					slot2 = 0;
					slot3 = 1;
					wait = true;
				}
			}
			if(wait == false) {
				if(slot3 == 1) {
					tmac = tmac + 1;
					slot3 = 0;
					slot1 = 1;
					wait = true;
				}
			}
			wait = false;
			
			Mjar = Mjar - 1;
			
		}

	}

}