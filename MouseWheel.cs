using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MouseWheel : MonoBehaviour
{
    private Camera cam;
    void Start(){cam = Camera.main;}
    void Update()
    {
        float mw = Input.GetAxis("Mouse ScrollWheel");
        if (mw != 0) cam.fieldOfView = Mathf.Clamp(cam.fieldOfView + cam.fieldOfView * mw * Time.deltaTime * 200f, 10f, 60f);
    }
}

