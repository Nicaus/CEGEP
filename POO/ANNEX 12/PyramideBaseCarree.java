package packageannex12;

public class PyramideBaseCarree extends Prisme{
    public PyramideBaseCarree(){
        super();
    }
    public PyramideBaseCarree(double arete, double hauteur){
        super(hauteur, arete, arete);
    }

//    public double apotheme(){
//        return (Math.pow(getHauteur(),2) + (Math.pow(getLargeur(),2)) / 2);
//    }

    public double aire(){
        double aireBase = getLargeur() * getLongeur();
        double apotheme = Math.pow(getHauteur(), 2) + Math.pow(getLargeur()/2, 2);
        apotheme = Math.pow(apotheme, 0.5);
        double aireCote = getLargeur() * apotheme / 2;
        return aireBase + 4 * aireCote;
    }

    public double volume() {
        return super.volume() / 3;
    }
}
