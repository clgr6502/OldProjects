import java.util.ArrayList;

public class Rubrica {
    private ArrayList<Persone> rubricaTelefonica;
    public Rubrica(){
        rubricaTelefonica = new ArrayList<>();
    }

    public void aggiungiContatto(Persone contatto){
        rubricaTelefonica.add(contatto);
    }

    public void stampaLista(){
        for(Persone indice : rubricaTelefonica) {
            System.out.println("################");
            System.out.println(indice.getNome() + " " + indice.getCognome() + ": " + indice.getNumero());
        }

    }
}
