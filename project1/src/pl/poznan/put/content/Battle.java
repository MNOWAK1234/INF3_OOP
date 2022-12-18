package pl.poznan.put.content;

public interface Battle {
	void showTeam(Team one);
	void prepare();
	int winner(boolean preference, int ovrFirst, int ovrSecond);
	void wholeLeague();
	void wholeSeason();
	void roadToGlory();
	void prepareResults();
	void simulate();
	void readResults();
}
