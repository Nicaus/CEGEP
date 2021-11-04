package annexe13;

public class Chalet extends Maison{
    /**
     * Constructeur : "initialise les variables d'un objet"
     *
     * @param nbrePieces
     * @param superficieTerrain
     * @param noAdresse
     * @param nomRue
     * @param prixVente
     */

    private boolean electricite;
    private boolean accesLac;

    public Chalet(int nbrePieces, double superficieTerrain, String noAdresse, String nomRue, double prixVente, boolean electricite, boolean accesLac) {
        super(nbrePieces, superficieTerrain, noAdresse, nomRue, prixVente);
        this.electricite = electricite;
        this.accesLac = accesLac;
    }

    // IS (GET)
    public boolean isElectricite() {
        return electricite;
    }

    public boolean isAccesLac() {
        return accesLac;
    }

    // SET
    public void setElectricite(boolean electricite) {
        this.electricite = electricite;
    }

    public void setAccesLac(boolean accesLac) {
        this.accesLac = accesLac;
    }

    // VALEUR
    @Override
    public double valeur() {
        double valeur = super.valeur() * 0.75;

        if (electricite)
            valeur *= 1.1;
        if (accesLac)
            valeur += 5000;

        return valeur;
    }
}
