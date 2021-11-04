package projectannex6;

public class CompteBanquaire {
     private String nomDetenteur;
     private double solde;
     private String numero;
    
     public CompteBanquaire (String nomDetenteur, double solde){
         this.nomDetenteur = nomDetenteur;
         this.solde = solde;
         numero = this.nomDetenteur.charAt(0) + "-" +
     }
}
