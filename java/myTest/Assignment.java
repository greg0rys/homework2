import java.util.*;

public class Assignment {
	String name;
	int grade;
	float weight;
	String gnum;
    Scanner lineReader = new Scanner(System.in);

	/**
	 * construct an assignment dynamically if wanted.
	 * @param userInput - if true we will read the fields in from a user
	 * else we will assign everything to an empty state.
	 */
	
	public Assignment(boolean userInput) {
			if(!userInput) {
					this.name = " ";
					this.grade = 0;
					this.weight = 0;
					this.gnum = " ";
			}
			else {
				System.out.println("Please enter a name: ");
				this.name = lineReader.nextLine();
				System.out.println("Please enter a grade: ");
				this.grade = lineReader.nextInt();
				System.out.println("Please enter the grades weight: ");
				this.weight = lineReader.nextFloat();
				System.out.println("Please enter a gnum: ");
				this.gnum = lineReader.nextLine();
				
			}
	}

	private void sayInfo() {
		System.out.println(this.name + " " + this.grade + " " + this.weight +
							" " + this.gnum);
	}	
}
