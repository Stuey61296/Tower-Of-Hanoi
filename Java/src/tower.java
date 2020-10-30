import java.util.LinkedList;
import java.util.Scanner;

public class tower {
    private int poleCount;
    private LinkedList<towerPole> poles;
    private int moveCount;

    public tower(int poleCount, int nodeCount) {
        this.poles = new LinkedList<towerPole>();
        this.setPoleCount(poleCount);
        this.setMoveCount(0);
        char name = 65;
        this.addPoles(new towerPole(nodeCount, false, name++));
        for (int i = 1; i < poleCount; ++i)
            this.addPoles(new towerPole(nodeCount, true, name++));
    }

    public void printTower() {
        print("________________________________________________________________________________\n");
        int[][] tower = new int[this.getPoleCount()][this.getPoles().peek().getNodeCount()];
        int poleCounter = 0, nodeCounter = 0;
        for (towerPole Pole : this.getPoles()) {
            poleNode pNode = Pole.getPoleHead();
            tower[poleCounter] = new int[Pole.getNodeCount()];
            while (pNode != null) {
                tower[poleCounter][nodeCounter++] = pNode.getValue();
                pNode = pNode.getNextNode();
            }
            ++poleCounter;
            nodeCounter = 0;
        }
        poleCounter = 0;
        nodeCounter = 0;
        for (int i = 0; i < this.getPoles().peek().getNodeCount(); ++i) {
            print("\t");
            for (int j = 0; j < this.getPoleCount(); ++j) {
                if (tower[j][i] == -1)
                    print("|");
                else
                    print(Integer.toString(tower[j][i]));
                print("\t\t");
            }
            println("");
        }
        print("\t");

        for (int i = 0; i < this.getPoleCount(); ++i)
            print("_\t\t");

        println("");
        print("\t");
        for (towerPole p : this.getPoles())
            print(String.valueOf(p.getPoleName()) + "\t\t");
        println("");
    }

    public void playGame() {
        Scanner scanner = new Scanner(System.in);
        while(!this.gameFinished()){
            char poleMoveFrom, poleMoveTo;
            println("Which pole would you like to move the top disk from (A - " + this.getPoles().getLast().getPoleName() + ") ?");
            poleMoveFrom = scanner.nextLine().toUpperCase().charAt(0);
            println("Which pole would you like to move the top disk to (A - " + this.getPoles().getLast().getPoleName() + ") ?");
            poleMoveTo = scanner.nextLine().toUpperCase().charAt(0);
            if(!this.getPoles().get(poleMoveFrom - 65).reallocatePole(this.getPoles().get(poleMoveTo - 65))){
                println("Invald move!");
                this.printTower();
                continue;
            }
            this.setMoveCount(this.getMoveCount()+ 1);
            println("");
            this.printTower();
        }
        println("________________________________________________________________________________\n\t\tCongratulations! Game completed in " + Integer.toString(this.getMoveCount()) + " moves.\n________________________________________________________________________________");
    }

    public boolean gameFinished() {
        poleNode lastPole = this.getPoles().getLast().getPoleHead();
        while (lastPole != null) {
            if (lastPole.getValue() == -1)
                return false;
            lastPole = lastPole.getNextNode();
        }
        return true;
    }

    public void addPoles(towerPole pole) {
        this.poles.add(pole);
    }

    public void print(String printString) {
        System.out.print(printString);
    }

    public void println(String printString) {
        System.out.println(printString);
    }

    public int getPoleCount() {
        return poleCount;
    }

    public void setPoleCount(int poleCount) {
        this.poleCount = poleCount;
    }

    public LinkedList<towerPole> getPoles() {
        return poles;
    }

    public void setPoles(LinkedList<towerPole> poles) {
        this.poles = poles;
    }

    public int getMoveCount() {
        return moveCount;
    }

    public void setMoveCount(int moveCount) {
        this.moveCount = moveCount;
    }
}

