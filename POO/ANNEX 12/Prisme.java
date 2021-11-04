package packageannex12;

public class Prisme {
    private double hauteur;
    private double longeur;
    private double largeur;

    public Prisme(){
        hauteur = 1;
        largeur = 1;
        longeur = 1;
    }

    public Prisme(double hauteur, double longeur, double largeur){
        this.hauteur = hauteur;
        this.largeur = largeur;
        this.longeur = longeur;
    }


    public double aire(){
//        return (2*(largeur * longeur)) + ((largeur + longeur) * hauteur);
        return 2*(longeur*largeur + longeur*hauteur + largeur*hauteur);
    }

    public double volume(){
        return largeur * longeur * hauteur;
    }

    public double getHauteur() {
        return hauteur;
    }

    public double getLargeur() {
        return largeur;
    }

    public double getLongeur() {
        return longeur;
    }

    public void setLongueur(double longueur) {
        this.longeur = longueur;
    }

    public void setHauteur(double hauteur) {
        this.hauteur = hauteur;
    }
}
