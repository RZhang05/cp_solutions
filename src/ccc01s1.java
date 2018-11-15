import java.util.*;
public class ccc01s1 {

	public static String cardValues[] = {"J", "Q", "K", "A"};
	public static String classes[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		String score = sc.next();
		int count = 0;
		String cards = "";
		int index = 0;
		int cardCount = 0;
		int total = 0;

		System.out.printf("%-20s %10s\n", "Cards Dealt", "Points");

		for(int i=0;i<score.length();i++) {
			String input = score.substring(i, i + 1);
			if(input.equals("D") || input.equals("H") || input.equals("S")) {
				if(cardCount == 0)
					count += 3;
				else if(cardCount == 1)
					count += 2;
				else if(cardCount == 2)
					count ++;
				System.out.printf("%-20s %10s\n", (classes[index] + " " + cards), count);
				total += count;
				index++;
				count = 0;
				cards = "";
				cardCount = 0;
			}
			else {
				if(!input.equals("C")) {
					cardCount++;
					cards += input + " ";
					for(int j=0;j<cardValues.length;j++) {
						if(cardValues[j].equals(input)) {
							count+= j + 1;
						}
					}
				}
			}
		}

		if(cardCount == 0)
			count += 3;
		else if(cardCount == 1)
			count += 2;
		else if(cardCount == 2)
			count ++;
		System.out.printf("%-20s %10s\n", (classes[index] + " " + cards), count);
		total += count;
		System.out.printf("%31s", ("Total " + total));

	}

}