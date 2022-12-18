package pl.poznan.put.content;

import java.util.Vector;
import java.util.Random;
import java.util.Collections;

public class Simulation implements Battle {
    private String sport;
    private Vector<Team>teams = new Vector<>();
    private Vector<Integer> scoringSheet = new Vector<>();
    private FootballLeague PremierLeague;
    private F1season season;
    public Simulation (String sport, Vector<Team> teams) {
        this.sport = sport;
        this.teams = teams;
    }
    public void showTeam(Team one) {
        System.out.println(one.name + " " + one.points + " " + one.ovr);
    }
    public void prepare() {
        PointsSystem points = new PointsSystem(this.sport);
        this.scoringSheet = points.scorage();
        if(this.sport.equals("Football")) {
            this.PremierLeague = new FootballLeague("League", this.teams);
        }
        else if(this.sport.equals("F1")) {
            this.season = new F1season();
        }
    }
    public int winner(boolean preference, int ovrFirst, int ovrSecond) {
        Random r = new Random();
        int result = r.nextInt(ovrFirst + ovrSecond) + 1;
        if(preference == true) result -= 100;
        if(result < ovrFirst - 50) return 0;
        else if (result <= ovrFirst + 50) return 1;
        else return 2;
    }
    public void wholeLeague() {
        Vector<Integer>pairing = new Vector<>();
        pairing = PremierLeague.generatePairing();
        if(pairing.get(0) == -2) {
            for(int i = 1; i < pairing.size(); i += 2) {
                int result = winner(true, this.teams.get(pairing.get(i)).strength(), this.teams.get(pairing.get(i+1)).strength());
                this.teams.get(pairing.get(i)).achievePoints(this.scoringSheet.get(result));
                if(result == 2) result = 0;
                else if (result == 0) result = 2;
                this.teams.get(pairing.get(i+1)).achievePoints(this.scoringSheet.get(result));
            }
        }
    }
    public void roadToGlory() {
        Vector<Boolean>eliminated = new Vector<>();
        for( int i = 0; i < this.teams.size(); i++) {
            eliminated.add(false);
        }
        int front = 0;
        int back = 31;
        for(int i = 0; i < 5; i++) {
            front = 0;
            back = 31;
            while(front < back) {
                if(eliminated.get(front) == false && eliminated.get(back) == false) {
                    if(winner(true, this.teams.get(front).strength(), this.teams.get(back).strength()) < 2) {
                        eliminated.set(back, true);
                        this.teams.get(front).achievePoints(1);
                        switch (i) {
                            case (0):
                            this.teams.get(back).result("Eliminated 1/16");
                            break;
                            case (1):
                            this.teams.get(back).result("Eliminated 1/8");
                            break;
                            case (2):
                            this.teams.get(back).result("Eliminated 1/4");
                            break;
                            case (3):
                            this.teams.get(back).result("Eliminated 1/2");
                            break;
                            case (4):
                            this.teams.get(back).result("2ND");
                            this.teams.get(front).result("1ST");
                            break;
                        }
                    }
                    else {
                        eliminated.set(front, true);
                        this.teams.get(back).achievePoints(1);
                        switch (i) {
                            case (0):
                            this.teams.get(front).result("Eliminated 1/16");
                            break;
                            case (1):
                            this.teams.get(front).result("Eliminated 1/8");
                            break;
                            case (2):
                            this.teams.get(front).result("Eliminated 1/4");
                            break;
                            case (3):
                            this.teams.get(front).result("Eliminated 1/2");
                            break;
                            case (4):
                            this.teams.get(front).result("2ND");
                            this.teams.get(back).result("1ST");
                            break;
                        }
                    }
                    front++;
                    back--;
                }
                else if (eliminated.get(front) == true) {
                    front++;
                }
                else if (eliminated.get(back) == true) {
                    back--;
                }
            }
        }
    }
    public void wholeSeason() {
        Vector<Integer>races = new Vector<>();
        races = season.publishCalendar();
        Vector<RaceResults>grandPrix = new Vector<>();
        int perf = 0;
        for(int i = 0; i < races.size(); i++) {
            for(int j = 0; j < this.teams.size(); j++) {
                perf = 0;
                Random r = new Random();
                for(int k = 0; k < races.get(i); k++) {
                    perf += r.nextInt(this.teams.get(j).strength()) + 1;
                }
                grandPrix.add(new RaceResults(j, perf));
            }
            Collections.sort(grandPrix, (d1, d2) -> d2.pace() - d1.pace());
            for(int j = 0; j < this.teams.size(); j++) {
                this.teams.get(grandPrix.get(j).racingNumber()).achievePoints(this.scoringSheet.get(j));
            }
            grandPrix.clear();
        }
    }
    public void prepareResults() {
        if(this.sport.equals("Football")) {
            Collections.sort(this.teams, (t1, t2) -> t2.tally() - t1.tally());
        }
        else if(this.sport.equals("F1")) {
            Collections.sort(this.teams, (t1, t2) -> t2.tally() - t1.tally());
        }
        else if(this.sport.equals("Cup")) {
            Collections.sort(this.teams, (t1, t2) -> t2.tally() - t1.tally());
        }
    }
    public void simulate() {
        this.prepare();
        if(this.sport.equals("Football")) {
            wholeLeague();
        }
        else if(this.sport.equals("F1")) {
            wholeSeason();
        }
        else if(this.sport.equals("Cup")) {
            roadToGlory();
        }
        this.prepareResults();
    }
    public void readResults() {
        if(this.sport.equals("Football")) {
            for(int i = 0; i < this.teams.size(); i++) {
                System.out.println(i+1 + ". " + this.teams.get(i).tellName() + " " + this.teams.get(i).tally());
            }
        }
        else if(this.sport.equals("F1")) {
            for(int i = 0; i < this.teams.size(); i++) {
                System.out.println(i+1 + ". " + this.teams.get(i).tellName() + " " + this.teams.get(i).tally());
            }
        }
        else if(this.sport.equals("Cup")) {
            for(int i = 0; i < this.teams.size(); i++) {
                System.out.println(this.teams.get(i).stage() + ": " + this.teams.get(i).tellName());
            }
        }
    }
}
