package annexe13;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class MaisonMobile extends Chalet{
    private int anneeFabrication;

    public MaisonMobile(int nbrePieces, double prixVente, boolean electricite, boolean accesLac, int anneeFabrication) {
        super(nbrePieces, 0, "", "", prixVente, electricite, accesLac);
        this.anneeFabrication = anneeFabrication;
    }

    public int getAnneeFabrication() {
        return anneeFabrication;
    }

    public void setAnneeFabrication(int anneeFabrication) {
        this.anneeFabrication = anneeFabrication;
    }

    @Override
    public double valeur() {
        GregorianCalendar aujourdhui = new GregorianCalendar();
        double age = aujourdhui.get(Calendar.YEAR) - super.valeur();
        double val = super.valeur();
        if (age < 19 && age > 10)
            return val *= 0.6;
        else if (anneeFabrication > 20)
            return val *= 0.5;
        else
            return val;
    }
}
