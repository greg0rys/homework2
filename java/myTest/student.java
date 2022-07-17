import java.util.*;

public class student {
		private String name;
		private String grade;
		private String gnum;
	    private	List<Assignment> assignments ;
		private List<student> roster;
		public student() {
				this.name = " ";
				this.grade = " ";
				this.gnum = " ";
				this.assignments = new ArrayList<>();
				this.roster = new ArrayList<>();
		}

		public student(String name, String grade, String gnum) {
				this.name = name;
				this.grade = grade;
				this.gnum = gnum;
				assignments = new ArrayList<>();
				this.roster = new ArrayList<>();
		}

		public String getName() {
				return this.name;
		}

		public String getGrade() {
				return this.grade;
		}

		public String getGnum() {
				return this.gnum;
		}

		public void setName(String name) {
				this.name = name;
		}

		public void setGrade(String Grade) {
				this.grade = grade;
		}

		public void setGnum(String gnum) {
				this.gnum = gnum;
		}

		private void buildFrame() {
				JFrame frame = new JFrame();
				frame.add(this);
				frame.setVisibile(true);
				frame.setPrefferedSize(new Dimension(650,500));
				frame.setDefaultCloseOperation(0); // system exit.
		}

				
}
