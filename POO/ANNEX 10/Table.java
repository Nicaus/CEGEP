package projetannexe10;

public class Table {

    private int nbPlaces;  // nb de places à cette table
    private int numero; // numéro identifiant la table
    private boolean banquette;  // si c'est une banquette
    private boolean occupe;  // si cette table est occupé ou non

    public Table ( int nbPlaces, int numero, boolean banquette )
    {
        this.nbPlaces = nbPlaces;
        this.numero = numero;
        this.banquette = banquette;
        occupe = false; // facultatif, la table n'est jamais occupée au départ
    }

    public int getNbPlaces() {
        return nbPlaces;
    }

    public int getNumero() {
        return numero;
    }

    public boolean isBanquette() {
        return banquette;
    }

    public boolean isOccupe() {
        return occupe;
    }

    public void setOccupe ( boolean occupe )
    {
        this.occupe = occupe;
    }
}
