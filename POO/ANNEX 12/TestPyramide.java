package packageannex12;

public class TestPyramide {
    public static void main(String[] args) {
        Prisme p1 = new Prisme();
        Prisme p2 = new Prisme(2,4,2);

        PyramideBaseCarree py1 = new PyramideBaseCarree();
        PyramideBaseCarree py2 = new PyramideBaseCarree(9, 6);

        Cube c1 = new Cube(35);


        p1.setLongueur(25);
        System.out.println("aire prisme 1:      "+p1.aire());
        System.out.println("volume prisme 2:    "+py2.volume());
        py1.setHauteur(35);
        System.out.println("volume prisme 1:    "+py1.volume());
        System.out.println("aire pyramide 2:    "+py2.aire());
        System.out.println("aire cube 1:        "+c1.aire());
    }
}
