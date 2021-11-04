package projectannex6;

public class Test {
    public static void main(String[] args) {
        CompteBanquaire Flavien = new CompteBanquaire("Flavien Larrivée", 100);
        CompteBanquaire Denise = new CompteBanquaire("Denise Lachance", 36.78);

        System.out.println(Flavien.getNom());
        //Denise.setSoldeCompte(Denise.getSolde() - 20);
        Denise.retrait(20);
        System.out.println("Numero de compte de Flavien : " + Flavien.getNoCompte());

        CompteBanquaire Martial = new CompteBanquaire("Martial Maurice", 40);

        System.out.println("Numero de compte de Martial : " + Martial.getNoCompte());
        System.out.println("Solde de Denise : " + Denise.getSolde());

    }
}
