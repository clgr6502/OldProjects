import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        System.out.println("Rubrica v1.0");
        Boolean active = true;
        Scanner userInput = new Scanner(System.in);

        Rubrica rubrica = new Rubrica();
        while (active) {
            System.out.println("1) Inserisci contatto\n2) Stampa contatti");
            System.out.println("3) Modifica contatto\n4) Esci");
            int scelta = userInput.nextInt();
            userInput.nextLine();

            switch (scelta) {
                case 1:
                    System.out.println("Inserisci il nome:");
                    String nome = userInput.nextLine();

                    System.out.println("Inserisci il cognome:");
                    String cognome = userInput.nextLine();

                    System.out.println("Inserisci il numero di telefono:");
                    int numero = userInput.nextInt();

                    Persone persone = new Persone(nome, cognome, numero);
                    rubrica.aggiungiContatto(persone);

                    break;
                case 2:
                    rubrica.stampaLista();
                    break;
                case 3:
                    break;
                case 4:
                    active = false;
                    break;
                default:
                    break;
            }
        }
    }
}
