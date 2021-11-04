package annexe13;

public class Maison {



// Données d'instance : valeurs différentes pour chaque objet Maison

        private int nbrePieces;
        private double superficieTerrain;
        private String noAdresse;
        private String nomRue;
        private double prixVente;


        /**
         * Constructeur : "initialise les variables d'un objet"
         */

        public Maison(int nbrePieces, double superficieTerrain, String noAdresse, String nomRue,  double prixVente)

        {
            this.nbrePieces = nbrePieces;
            this.superficieTerrain = superficieTerrain;
            this.noAdresse = noAdresse;
            this.nomRue = nomRue;
            this.prixVente = prixVente;
        }


        // méthode permettant d'accéder à la donnée privée nbrePieces

        public int getPieces ()
        {
            return nbrePieces;
        }

        // méthode permettant d'ajouter un nombre de pièces à la maison

        public void ajouterPieces ( int nbreSupPieces )
        {
            nbrePieces = nbrePieces + nbreSupPieces;
        }


        public double getSuperficie ()
        {
            return superficieTerrain;
        }


        public  void setSuperficie (double superficieTerrain)
        {
            this.superficieTerrain = superficieTerrain;
        }


        public String getAdresse ()
        {
            return noAdresse;
        }


        public String getRue ()
        {
            return nomRue;
        }


        public double getPrixVente ()
        {
            return prixVente;
        }


        public void setPrixVente ( double prixVente )
        {
            this.prixVente = prixVente;
        }


        public double valeur ()
        {
            return 39000 * nbrePieces + 4*superficieTerrain;
        }

        public boolean meilleureAffaire ( Maison autreMaison )
        {
            if (( valeur() - prixVente ) > (autreMaison.valeur() - autreMaison.prixVente))
                return true;
            else
                return false;
        }


    }





