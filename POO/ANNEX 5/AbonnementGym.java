package projectannex5;

public class AbonnementGym {
    private String nomMembre;
    private int duree;
    private double prix;

    //base
    public AbonnementGym(String nomMembre){
    this.nomMembre = nomMembre;
    duree = 30;
    prix = 41.25;
    }

    //a la carte
    public AbonnementGym(int duree, String nomMembre){
    this.nomMembre = nomMembre;
    if (duree >= 0)
        this.duree = duree;
    prix = 8.25 * duree;
    }

    //vip
    public AbonnementGym(String nomMembre, int duree, double prix){
        this.nomMembre = nomMembre;
        this.duree = duree;
        this.prix = prix;
    }

    public double getPrix(){
        return prix;
    }

    public void setPrix(double prix) {
        this.prix = prix;
    }

    public void setDuree(int duree) {
        this.duree = duree;
    }

    public void setNomMembre(String nomMembre) {
        this.nomMembre = nomMembre;
    }

    public int getDuree(){
        return duree;
    }

    public String getNomMembre(){
        return nomMembre;
    }
}

