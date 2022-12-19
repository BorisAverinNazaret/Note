using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using UnityEngine;
using Vector3 = UnityEngine.Vector3;

public class Planet2 : MonoBehaviour
{
    //        new Planet("P000000", 0f, 2000f, 0f, new Vector3(0f, 0f, 0f), MainColor);
    //        new Planet("P000001", -0.2f, 20f, 1f, new Vector3(0f, 0f, 1100f), MainColor);

 //   public Color MainColor = new(0.8679f, 0.6792f, 0.4292f, 1f);
    public class Create
    {
        private GameObject planet;
        public Create(string name, float AngularVelocity, float radius, float _mass, Vector3 place, Color color)
        {


            planet = GameObject.CreatePrimitive(PrimitiveType.Sphere);  //Sphere Capsule Cylinder Cube Plane Quad
            planet.transform.position = place;
            planet.name = name;
            planet.transform.localScale = new Vector3(radius, radius, radius);


            planet.AddComponent<Rigidbody>();
            planet.GetComponent<Rigidbody>().isKinematic = true;
            planet.GetComponent<Rigidbody>().detectCollisions = true;


            planet.GetComponent<Rigidbody>().mass = radius / 20f;


            planet.GetComponent<SphereCollider>().radius = radius + radius;
            planet.GetComponent<SphereCollider>().isTrigger = true;

            planet.GetComponent<MeshRenderer>().material.color = color;
            if (name == "P000000")
            {
                planet.GetComponent<MeshRenderer>().material.SetColor("_EmissionColor", color);
                planet.GetComponent<MeshRenderer>().material.SetFloat("_Glossiness", 0f);
            }
/*
            parent_name = name.Substring(0, 1) + "0000" + name.Substring(5);
            var sputnik = planet.name != parent_name;


            planet_parent = !sputnik ? GameObject.Find("P000000") : GameObject.Find(parent_name);
            planet.transform.parent = planet_parent.transform;
*/
            if (name != "P000000") planet.AddComponent<Rotation010>();




        }
    }

    public Create planet2 = new Create("P009900", 0f, 2000f, 0f, new Vector3(0f, 0f, 10000f), new Color(0.8679f, 0.6792f, 0.4292f, 1f));



    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }

}
