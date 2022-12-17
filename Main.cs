using System;
using UnityEngine;
using System.Collections;
using UnityEditor;
using UnityEngine.UI;
using Random = System.Random;
using System.Numerics;
using Vector3 = UnityEngine.Vector3;
//using Unity.VisualScripting;

class Main : MonoBehaviour
{
    public Light LightCentre;
    public static GameObject CENTRE;
    public Color MainColor = new(0.8679f, 0.6792f, 0.4292f, 1f);
    public Vector3 CentreRotateAround;
    public GameObject myGO;
    public Random rnd = new();

    // Время старта
    private float startTime;

    public const float ae = 149_597_870.691f; //149597870.691f;
    public float aeg = 10_000.000f;

    [Obsolete]
    void Awake()
    {
        GameObject ML = GameObject.Find("Directional Light");
        ML.active = false;

        AudioSource aud = Camera.main.GetComponent<AudioSource>();

        //    Create(string name, int lengthSamples, int channels, int frequency, bool stream);
        //  AudioClip myClip = AudioClip.Create("9", 44100 * 2, 1, 44100, true);
 //       aud.clip =  (AudioClip)AudioClip.Create("9", 8000, 1, 44100, false);
        aud.volume = 0.5f;
        aud.loop = true;
        aud.playOnAwake = true;

     //   aud.clip = myClip;
        aud.Play();

    }
    void Start()
    {

        startTime = Time.time;


        //  Объект визуализации центра
        CENTRE = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        CENTRE.name = "CENTRE";
        CENTRE.transform.position = Vector3.zero;
        CENTRE.transform.localScale = new Vector3(0.006f, 0.006f, 0.006f);
        Renderer rendCENTRE = CENTRE.GetComponent<Renderer>();
        rendCENTRE.material.color = Color.yellow;

        GameObject lightObj = new("LightCentre");
        Light lightCentre = lightObj.AddComponent<Light>();
        lightCentre.shadowStrength = 0f;
        lightCentre.shadowRadius = 0f;

        lightCentre.type = LightType.Point;
        lightCentre.transform.position = new Vector3(0, 0, 0);
        lightCentre.color = MainColor;
        lightCentre.intensity = 1.5f;
        lightCentre.range = 70000f;


        /*
                ============================================================
                CameraSkybox.name = "CameraSkybox";
                CameraSkybox.transform.localEulerAngles = new Vector3(0f, 0f, 60f);
                //   CameraSkybox.targetDisplay. = target;

                ============================================================
                public GameObject hand;
                hand = GameObject.Find("Hand");

                ============================================================
                // Автоматическое удаление объекта 
                // ~spaceship() {Debug.Log("Ded spaceship");}


                */


        myGO = new GameObject();
        myGO.name = "TestCanvas";
        myGO.AddComponent<Canvas>();
        Canvas myCanvas = myGO.GetComponent<Canvas>();
        myCanvas.renderMode = RenderMode.ScreenSpaceOverlay;
        myGO.AddComponent<Text>();
        Text textComponent = myGO.GetComponent<Text>();
        Material newMaterialRef = Resources.Load<Material>("3DTextCoolVetica");
        Font myFont = Resources.Load<Font>("coolvetica rg");

        textComponent.font = myFont;
        textComponent.material = newMaterialRef;
        textComponent.text = "Hello World";
        myGO.AddComponent<Slider>();







        GameObject Spaceship = GameObject.CreatePrimitive(PrimitiveType.Cube);

        Spaceship.name = "Spaceship";
        Spaceship.transform.localScale = new Vector3(0.06f, 0.02f, 0.6f);
        Spaceship.transform.position = Vector3.zero;

        Spaceship.transform.position = new Vector3(3000f, 0, 0);
        Spaceship.transform.Rotate(new Vector3(0, -90, 0));

        Renderer rendSpaceship = Spaceship.GetComponent<Renderer>();
        rendSpaceship.material.color = Color.gray;
        //   rendSpaceship.material.

        Spaceship.AddComponent<Rigidbody>();
        Spaceship.GetComponent<Rigidbody>().useGravity = false;
        Spaceship.GetComponent<Rigidbody>().isKinematic = false;
        Spaceship.GetComponent<BoxCollider>().size = new Vector3(0.06f, 0.02f, 0.6f);
        Spaceship.GetComponent<BoxCollider>().isTrigger = false;

        Spaceship.AddComponent<PlayerController>();

        ////////////////////////////////////////////////////////////////////
        //  Camera.main.Reset();
        Camera.main.transform.parent = Spaceship.transform;
        Camera.main.transform.position = Vector3.zero;
        Camera.main.transform.localPosition =
            new Vector3(0,
                        Spaceship.transform.position.y + 2f,
                        Spaceship.transform.position.z - 0f);
        Camera.main.transform.Rotate(new Vector3(0, -90, 0));
        Camera.main.farClipPlane = 1000_000f;
        Camera.main.nearClipPlane = 0.01f;

        // для колеса мыши
        Camera.main.gameObject.AddComponent<MouseWheel>();


        GameObject P000003 =  new Planet2();

        new Planet("P000000", 0f, 2000f, 0f, new Vector3(0f, 0f, 0f), MainColor);
        new Planet("P000001", -0.2f, 20f, 1f, new Vector3(0f, 0f, 1100f), MainColor);
        new Planet("P000002", -1f, 80f, 1f, new Vector3(0f, 0f, 1400f), MainColor);

        new Planet("P000003", -3f, 60f, 1f, new Vector3(0f, 0f, -2400f), MainColor);
        new Planet("P000103", -1f, 2f, 1f, new Vector3(0f, 0f, -2335f), MainColor);
        new Planet("P000203", -2f, 2f, 1f, new Vector3(65f, 0f, -2400f), MainColor);

        new Planet("P000004", -1f, 30f, 1f, new Vector3(0f, 0f, 500f), MainColor);

        new Planet("P000005", -0.3f, 300f, 1f, new Vector3(0f, 0f, -3000f), MainColor);
        new Planet("P000105", -0.3f, 4f, 1f, new Vector3(0f, 0f, -2845f), MainColor);
        new Planet("P000205", -0.4f, 2f, 1f, new Vector3(0f, 0f, -3155f), MainColor);
        new Planet("P000305", -0.4f, 2f, 1f, new Vector3(160f, 0f, -3000f), MainColor);

        new Planet("P000006", -0.2f, 200f, 1f, new Vector3(0f, 0f, 3700f), MainColor);
        new Planet("P000007", -3.7f, 50.35f, 1f, new Vector3(0f, 0f, 4400f), MainColor);
        new Planet("P000008", -2.8f, 50.9f, 1f, new Vector3(0f, 0f, 5300f), MainColor);


        /*
        aeg = 10000f; // 149_597_870.691f;           Наклонение к плоскости Млечного Пути    60,19°
        // Солнечная система
        Planet.Generation("P000", 700.000f, 0f, 0f, 0f);          //  R 696000,7 км
        Planet.Generation("P100",   2.439f, 0f, 0f, aeg * 0.387f);//  R   2439,7 км  L 0,386ае (57 744 778,086)     m 0,055274 земной v 47,36 км/с  накл-ние 3,38°  относительно солн. экватора
        Planet.Generation("P200",   6.051f, 0f, 0f, aeg * 0.723f);//  R   6051,8 km  L 0,72333199  m 0,815    земной v 35,02 км/с  накл-ние 3,86°
        Planet.Generation("P300",   6.365f, 0f, 0f, aeg         );//  R   6365,0 km  L 1,00000261  m 1        земной v 29,79 км/с  накл-ние 7,155°
        Planet.Generation("P400",   3.385f, 0f, 0f, aeg * 1.524f);//  R   3385,0 km  L 1,5235      m 0,107    земной v 24,13 км/с  накл-ние 5,65°
        Planet.Generation("P500",  69.911f, 0f, 0f, aeg * 5.203f);//  R  69911,0 km  L 5,2042665   m 317,8    земной v 13,07 км/с  накл-ние 6,09°  Наклон оси 3,13°
        Planet.Generation("P600",  60.100f, 0f, 0f, aeg * 9.539f);
        Planet.Generation("P700",   5.350f, 0f, 0f, aeg * 19.19f);
        Planet.Generation("P800",   5.900f, 0f, 0f, aeg * 30.06f);
       */

    }

}


