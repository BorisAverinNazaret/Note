using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using UnityEngine;
using Vector3 = UnityEngine.Vector3;

public class Planet : MonoBehaviour
{
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
            //  planet.AddComponent<Gravity>();

            /*

                    GameObject lightObj = new ("LightForShade");
                    planet.AddComponent<Light>();
                    lightCentre.shadowStrength = 0f;
                    lightCentre.shadowRadius = 0f;

                    planet.GetComponent<Light>().type =  ;
                    lightCentre.transform.position = new Vector3(0, 0, 0);
                    lightCentre.color = MainColor;
                    lightCentre.intensity = 1.5f;
                    lightCentre.range=70000f;
            */

        }
    }
}







/*

Debug.Log($"Модуль вектора: {transform.position.magnitude}, квадрат модуля {transform.position.sqrMagnitude}, напровление вектора {transform.position.normalized}");
Debug.DrawRay(Vector3.zero, Vector3.up, Color.black);


public static void SetSuundplanet(GameObject objName, string soundName)
    {
        
        //    Create(string name, int lengthSamples, int channels, int frequency, bool stream);
    AudioSource aud =  planet.GetComponent<AudioSource>();
    AudioClip myClip =  AudioClip.Create("Track 09", 500000, 1, 44100, false);
    aud.volume /= 2;
    aud.loop = true;

    aud.clip = myClip;
    aud.Play();
        
    }
*/



