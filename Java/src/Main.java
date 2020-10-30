import java.util.Scanner;

import static java.lang.Math.pow;

public class Main {

    public static void main(String[] args) {
        int poleCounter, diskCounter;
        Scanner scanner = new Scanner(System.in);

        System.out.println("-----------------------------------------------------------------\n\t\t\tTower of Hanoi\n-----------------------------------------------------------------\n\n");
        System.out.println("Game details:\tThe objective of this game is to\nmove the disks(in this case numbers) from pole A\nto the end pole. In this version a disk may be moved to any pole.\nDisks with larger numbers may not sit ontop of disks with\nsmaller numbers. A maximum of 5 poles may be used\nand a minimum of 3 poles may be used. A minimum of 2 disks may be used.\n------------------------------------------------------------------");
        System.out.print("How many poles would you like to have? ");
        poleCounter = Integer.parseInt(scanner.nextLine());
        System.out.print("How many disks would you like to have? ");
        diskCounter = Integer.parseInt(scanner.nextLine());
        if (poleCounter > 5)
            poleCounter = 5;
        if (poleCounter < 3)
            poleCounter = 3;
        if (diskCounter < 2)
            diskCounter = 2;
        tower toh = new tower(poleCounter, diskCounter);
        toh.printTower();
        if (poleCounter == 3)
            System.out.println("Minimum moves to complete game: " + (pow(2, diskCounter) - 1));
        toh.playGame();
    }
}
