public class Persone {
    private String nome;
    private String cognome;

    private int numero;
    public Persone(String nome, String cognome, int numero){
        this.nome = nome;
        this.cognome = cognome;
        this.numero = numero;
    }

    public String getNome(){
        return nome;
    }

    public String getCognome(){
        return cognome;
    }

    public int getNumero(){
        return numero;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }
}
