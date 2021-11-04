package projectannex5;

public class TestConstructeur {

    public static void main(String[] args) {
        AbonnementGym a1 = new AbonnementGym("Lemar");
        AbonnementGym a2 = new AbonnementGym(12, "Sean");
        AbonnementGym a3 = new AbonnementGym("Roberto", 25, 12);

        //System.out.println(a2.duree); //impossible car prix is private dans AbonnementGym
        System.out.println(a2.getPrix()); //maintenant ca marche
        System.out.println(a2.getDuree());

        a2.setPrix(23);
        a2.setDuree(3);
        System.out.println(a2.getPrix());
        System.out.println(a2.getDuree());

        System.out.println(a3.getNomMembre());
        System.out.println(a1.getNomMembre());
    }
}
