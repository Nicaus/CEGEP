package projetannexe10;

public class Restaurant {
    private Table[] t;

    public Restaurant() {
        t = new Table[75];
        for (int i = 0; i < 30; i++) {
            t[i] = new Table(4, i + 1, true);
        }
        for (int i = 30; i < 60; i++) {
            t[i] = new Table(2, i + 1, true);
        }
        for (int i = 60; i < 70; i++) {
            t[i] = new Table(4, i + 1, false);
        }
        for (int i = 70; i < 75; i++) {
            t[i] = new Table(2, i + 1, false);
        }
    }

    public int nbTableOcupees() {
        int nb = 0;
        for (int i = 0; i < t.length; i++) {
            if (t[i].isOccupe()) {
                nb++;
            }
        }
        return nb;
    }

    public Table[] getT() {
        return t;
    }

    public Table assignerTableDispo(int nbPersonne, boolean desireBanquette) {
        int i = 0;
        while (i < t.length) {
            if (!t[i].isOccupe())
                if (t[i].getNbPlaces() >= nbPersonne)
                    if (t[i].isBanquette() == desireBanquette) {
                        t[i].setOccupe(true);
                        return t[i];
                    }
            i++;
        }
        return null;
    }

    public boolean verifierSiTableOccupe (int numero){
        return t[numero-1].isOccupe();
    }
}